#!@PREFIX@/bin/perl

# Copyright (c) 2002, 2003, 2004 by Andrew Brown <atatat@netbsd.org>
# Absolutely no warranty.

# $NetBSD: pkgdepgraph.pl,v 1.11 2005/06/26 17:34:19 atatat Exp $
# pkgdepgraph: @DISTVER@

use strict;
# no strict 'refs';

use Getopt::Long;
Getopt::Long::Configure("bundling");
my(@opts, %opt);
my($iam, $version, $usecolor, $group, $locations, $order, $versions);
my($limit, $delete, $rebuild, $force, @outofdate, @update, $clean);
my($pkg_dbdir, $pkgsrcdir, $packages, $pkgadd, $fetch, $make);
my($all, $target, $exists, $reverse, $simple, @subgraph, @impact, %impactof);

$version = '@DISTVER@';
($iam = $0) =~ s:.*/::;
@opts = ('A', 'a+', 'C', 'c', 'D', 'd=s', 'e', 'F', 'f', 'g', 'i=s',
	 'K=s', 'L', 'l', 'M=s', 'm=s', 'O=s', 'o', 'P=s', 'R', 'r',
	 'S=s', 's', 't=s', 'U=s', 'v');

%opt = (
	'A' => \$pkgadd,
	'a' => \$all,
	# 'C' => implies "realclean", handled later
	# 'c' => implies "clean", handled later
	'D' => \$delete,
	'd' => \$pkg_dbdir,
	'e' => \$exists,
	'F' => \$fetch,
	'f' => \$force,
	'g' => \$group,
	'i' => \@impact,
	'K' => \$packages,
	'L' => \$limit,
	'l' => \$locations,
	'M' => \$make,
	'm' => \$target,
	'O' => \@outofdate,
	'o' => \$order,
	'P' => \$pkgsrcdir,
	'R' => \$rebuild,
	'r' => \$reverse,
	'S' => \@subgraph,
	's' => \$simple,
	# 't' => goes to rebuild, handled later
	'U' => \@update,
	'v' => \$versions,
	);
die("usage: $iam [-AaCcDeFfgLloRrsv] [-d pkg_dbdir] [-i impact]\n",
    " " x (length($iam) + 8),
    "[-K packages] [-M make] [-m target] [-O package]\n",
    " " x (length($iam) + 8),
    "[-P pkgsrcdir] [-S package] [-t target] [-U package]\n",
    " " x (length($iam) + 8),
    "[data ...]\n")
    if (!GetOptions(\%opt, @opts));

die("$iam: -D, -F, -m, and -R are mutually exclusive -- please pick one\n")
    if (($delete != 0) + 
	($fetch != 0) +
	($target ne "") +
	($rebuild ne "") > 1);

$pkg_dbdir ||= $ENV{'PKG_DBDIR'} || "@PKG_DBDIR@";
$pkgsrcdir ||= $ENV{'PKGSRCDIR'} || "@PKGSRCDIR@";
$packages = $ENV{'PKG_PATH'} if (!$packages);
$packages = $ENV{'PACKAGES'} . "/All" if (!$packages && $ENV{'PACKAGES'});
$packages = $pkgsrcdir . "/packages/All" if (!$packages);
$rebuild &&= $opt{t} || "install";
$clean = "clean" if ($opt{c});
$clean = "CLEANDEPENDS=YES clean" if ($opt{C});
$make ||= $ENV{'MAKE'} || "make";

my(@pkgs, $pkg, $req, %req, %dep, @reqs, @rreqs);
my(%clusters, $cluster);
my(%where, $pkgcnt, $num, %num, @num, %ord, $suffix);
my(%color, $color, %vuln);
my(%need, %forced, $label);
my($recolor, @graph);
my(%vpkgs);

# @pkgs		- list of all installed pkgs
# %req		- pkg to ref to hash of pkgs that it requires
# %dep		- pkg to ref to hash of pkgs that depend on it
# %clusters	- pkg prefix to number of pkgs that share the prefix
# %where	- pkg to location in source tree
# %num/@num	- pkg to group number/group number array ref
# %ord		- pkg to its height in the tree
# %color	- pkg to pkg color (green, yellow, red, etc)
# %vuln		- pkg to vulnerabilities recorded against it
# %need		- pkg to version required (pkg is out of date) 
# %forced	- pkg marked as "forced" to be out of date
# %vpkgs	- pkg is viewable (part of selected subgraph)

##
## load out-of-date or security problem list (if given), or a graph to
## recolor
##
$recolor = 0;
if (@ARGV || ! -t) {
    $usecolor = 1;
    while (<>) {
	if (/^digraph/) {
	    $recolor = 1;
	    @graph = ($_);
	}
	elsif ($recolor > 0) {
	    push(@graph, $_);
	    $recolor++ if (/^subgraph/);
	    $recolor-- if (/^\}/);
	    $recolor -= ($recolor == 0);
	}
	elsif (m:^([^/\s]+)\t([^/\s]+/[^/\s]+)\t(\d+[^/\s]*)$:) {
	    $where{"$1-$3"} = $2;
	}
	elsif (/^Version mismatch: '(\S+)' (\S+) vs (\S+)/) {
	    $color{"$1-$2"} = "red";
	    $need{"$1-$2"} = "$1-$3";
	}
	elsif (/^Unknown package: '(\S+)' version (\S+)/) {
	    $color{"$1-$2"} = "purple";
	}
	elsif (/Package (\S+) has a (\S+) vulnerability/) {
	    $vuln{$1} = $2;
	    $color{$1} = "red";
	}
    }
}

##
## load pkg list
##
opendir(P, $pkg_dbdir) || die("opendir");
@pkgs = grep(/-/ && -d "$pkg_dbdir/$_" && -f "$pkg_dbdir/$_/+BUILD_INFO",
	     readdir(P));
closedir(P);
$pkgcnt = @pkgs;

##
## where are they needed
##
foreach $pkg (@pkgs) {
    $where{$pkg} ||= $pkg;
    open(R, "<$pkg_dbdir/$pkg/+BUILD_INFO") ||
	die("$pkg: +BUILD_INFO: $!\n");
    while (<R>) {
	if (/^PKGPATH\s*=\s*(\S+)/) {
	    $where{$pkg} = $1 if ($where{$pkg} eq $pkg);
	    last;
	}
    }
    close(R);
    next if (!open(R, "<$pkg_dbdir/$pkg/+REQUIRED_BY"));
    while ($req = <R>) {
	chomp($req);
	$req{$req}->{$pkg} = 1;
	$dep{$pkg}->{$req} = 1;
    }
    close(R);
}

##
## reset %where based on "better" information, if we have it
##
foreach $pkg (@pkgs) {
    if ($need{$pkg} && $where{$need{$pkg}}) {
	$where{$pkg} = $where{$need{$pkg}};
    }
}

##
## if we're recoloring an existing graph, recolor it now and finish
##
if ($recolor) {
    my(%over, %nver, @label, $ocolor);
    map({ /(.*)-(.*)/ && ($nver{$1} = $2) } @pkgs);

    foreach (@graph) {
	# we don't recolor edges
	($pkg) = (/\"([^\"]+)\"/);
	$pkg =~ s/(.*)-(.*)/$1/;
	$over{$pkg} = $2;

	if (/, EDGE$/) {
	    if (defined($nver{$pkg})) {
		s/color=\"[^\"]+\"/color=\"green\"/;
	    }
	    else {
		s/color=\"[^\"]+\"/color=\"black\"/;
	    }
	}

	elsif (/label=/) {
	    s/color=\"([^\"]+)\"/color="NEWCOLOR"/;
	    $ocolor = $1;
	    s/label=\"([^\"]+)\"/label="NEWLABEL"/;
	    $label = $1;
	    if ($nver{$pkg}) {
		if ($nver{$pkg} ne $over{$pkg} || $ocolor ne "red") {
		    s/NEWCOLOR/green/;
		}
		else {
		    s/NEWCOLOR/$ocolor/;
		}

		@label = split(/\\n/, $label);
		$label = "";

		# "where" tag
		if ($label[0] =~ m:/:) {
		    $label .= "\\n" . shift(@label);
		}

		# installed pkg
		$label[0] =~ s/(.*$pkg)-\S*$/$1-$nver{$pkg}/ if ($nver{$pkg});
		$label .= "\\n" . shift(@label);

		# "needed" pkg
		if ($label[0] =~ /^$pkg-(.*)/) {
		    $label .= "\\n$label[0]" if ($1 ne $nver{$pkg});
		    shift(@label);
		}

		# there shouldn't be anything left, but...
		$label .= "\\n" . join("\\n", @label);

		$label =~ s/\\n//;
	    }
	    else {
		s/NEWCOLOR/black/;
	    }
	    s/NEWLABEL/$label/;
	}
	print;
    }
    exit(0);
}

##
## eliminate redundancies by deleting edges that are redundant
##
foreach $pkg (@pkgs) {
    @reqs = sort(keys %{$req{$pkg}});
    @rreqs = recurse(\%req, @reqs);
    map(delete($req{$pkg}->{$_}), @rreqs);

    @reqs = sort(keys %{$dep{$pkg}});
    @rreqs = recurse(\%dep, @reqs);
    map(delete($dep{$pkg}->{$_}), @rreqs);
}

##
## create a hash of clusters of package prefixes, with counts.  later,
## clusters that have more than one member can be marked as subgraphs.
##
## the outer map() iterates over each pkg name after all instances of
## _ in the pkg name have been changed to - (for the purposes of
## accurate clustering).  the inner map() breaks each pkg name up into
## tokens that end in - and loops over the resulting list, appending
## each one to $a.  for example:
##
##	pkg:	one_two-three-4.56
##	tokens:	one-     two-         three-
##	$a:	one- one-two- one-two-three-
##
map({ $a = "";
      ($b = $_) =~ s/_/-/g;
      map({ $a .= $_; $clusters{$a}++; }
	  $b =~ /([^-]*-)/g); }
    @pkgs);

##
## impose some sort of order on the pkgs by assigning them numbers
## that indicate their height in the graph.  leaf pkgs will always
## have an order of 1, and each pkg above will be numbered at least 2
## (possibly higher, if there exists another longer path to another
## leaf).
##
map(order(1, $_), @pkgs);

##
## assign each pkg a group number, and count the number of pkgs in
## that group.  the group numbers are arbitrary, and serve only to
## identify pkgs that belong to the same group.
##
$num = 1;
foreach $pkg (@pkgs) {
    my($pkgnum);
    # my direct requirements
    @reqs = sort(keys %{$req{$pkg}});
    # all the requirements of my requirements
    @rreqs = recurse(\%req, @reqs);
    # the lowest group number from all of those
    $pkgnum = number($pkg, @reqs, @rreqs) || $num;
    # stuff all those into the list for that group 
    push(@{$num[$pkgnum]}, $pkg, @reqs, @rreqs);
    # now check for packages coming from other groups
    foreach $req ($pkg, @reqs, @rreqs) {
	# no group yet, skip on
	next if (!$num{$req});
	# was $req in a different group
	if ($num{$req} != $pkgnum) {
	    # yes, pull that group into the current group 
	    push(@{$num[$pkgnum]}, @{$num[$num{$req}]});
	    # empty out the old group
	    @{$num[$num{$req}]} = ();
	}
    }
    # reduce the group list
    @{$num[$pkgnum]} = uniq(sort(@{$num[$pkgnum]}));
    # make sure all packages in this group know 
    map($num{$_} = $pkgnum, @{$num[$pkgnum]});
    # skip to next available group number
    $num += ($num == $pkgnum);
}

##
## if we want to check a specific pkg for rebuild impact, mark it as
## "forced" to be out of date, unless it already *is* out of date.
##
if (@outofdate) {
    $usecolor = 1;
    canonicalize(@outofdate);

    foreach (@outofdate) {
	if ($color{$_} ne "red") {
	    $color{$_} = "red";
	    $need{$_} = $_;
	    $forced{$_} = " (forced)";
	}
    }
}

##
## if we want to update a specific package, mark all non-related
## packages as "green".  this avoids rebuilding unnecessary pkgs that
## don't depend on any of the same dependencies as the given pkg.  if
## $force is set, mark *all* dependencies of the given pkg as out of
## date.
##
if (@update) {
    my(@leftover);

    canonicalize(@update);
    @update = uniq(sort(@update, recurse(\%req, @update)));

    if ($force) {
	foreach (@update) {
	    if ($color{$_} ne "red") {
		$color{$_} = "red";
		$need{$_} = $_;
		$forced{$_} = " (forced)";
	    }
	}
    }

    foreach (sort(@pkgs)) {
	if ($_ eq $update[0]) {
	    shift(@update);
	}
	else {
	    push(@leftover, $_);
	}
    }

    delete(@color{@leftover});
    delete(@need{@leftover});
}

##
## pick packages for a subgraph
##
## + means up from given package, - means down, ++ means all the way
## up, -- means all the way down, = means all "connected" packages, etc.
##
if (@subgraph) {
    my ($sub, $up, $down, $eq);
    foreach (@subgraph) {
	($sub) = (/^([-+=]+)/);
	s/^[-+=]+//;
	$sub = "+-" if ($sub eq "");
	canonicalize($_);
	$up = join("", ($sub =~ /(\+)/g));
	$down = join("", ($sub =~ /(-)/g));
	$eq = join("", ($sub =~ /(=)/g));
	if ($eq) {
	    map($vpkgs{$_} = 1, @{$num[$num{$_}]});
	}
	else {
	    if ($up) {
		@reqs = sort(keys %{$req{$_}});
		@rreqs = (length($up) > 1) ? recurse(\%req, @reqs) : ();
		map($vpkgs{$_} = 1, ($_, @reqs, @rreqs));
	    }
	    if ($down) {
		@reqs = sort(keys %{$dep{$_}});
		@rreqs = (length($down) > 1) ? recurse(\%dep, @reqs) : ();
		map($vpkgs{$_} = 1, ($_, @reqs, @rreqs));
	    }
	}
    }
}
else {
    @vpkgs{@pkgs} = (1) x @pkgs;
}

##
## if checking for rebuild impact, also mark packages that are too
## deeply involved as "green" so that they're not candidates for
## destruction
##
if (@impact) {
    my ($impact);

    # step 1: canonicalize anything that's not a number (ie, is the
    # name of a pkg) and eliminate duplicates (we just don't need 'em)
    foreach (@impact) {
	next if (/^\d+$/);
	canonicalize($_);
    }
    @impact = uniq(sort(@impact));

    # step 2: the "default" impact allows for anything to be rebuilt,
    # but numeric values in @impact are also allowed, so pick the
    # lowest one (specifying both 1 and 2 really means just 1)
    $impact = $ord{(sort(byord @pkgs))[0]};
    while ($impact[0] =~ /^\d+$/) {
	$_ = shift(@impact);
	$impact = $_ if ($_ < $impact);
    }

    # step 3: anything that would have too great an impact on the tree
    # gets marked (the impactof() function will check the @impact
    # array to avoid specific pkgs being rebuild)
    foreach $pkg (keys %vpkgs) {
	next if (impactof($impact, $pkg) <= $impact);
	$vpkgs{$pkg} = 2;
    }

    # step 4: anything so marked gets tagged as green.  this tagging
    # is a separate step so that we can properly judge impact over the
    # entire tree (marking too early could prematurely split chunks
    # that need to be rebuilt)
    foreach $pkg (keys %vpkgs) {
	$color{$pkg} = "green" if ($vpkgs{$pkg} == 2);
    }
}

##
## translate "older" alternate output modes to the new generic version
##
if ($fetch) {
    $target = "fetch";
}
elsif ($rebuild) {
    $exists = 1;
    $limit = 1;
    $target = $rebuild;
}
elsif ($delete) {
    $all++;
    $simple = 1;
}

##
## "target" output mode, ordered by ascendency
##
if ($target || $simple) {
    my(@targets);
    printf("PKG_PATH=\"$packages\"\nexport PKG_PATH\n")
	if ($pkgadd && $rebuild);
    @targets = grep((color($_) eq "red" && !$limit) ||
		    (color($_) ne "green" &&
		     ($all || ($ord{$_} == 1 && $limit))) ||
		    ($all > 1), keys %vpkgs);
    @targets = sort(byord @targets);
    @targets = reverse(@targets) if (!$reverse);
    print_package(@targets);
    print("true\n") if (!$simple);
    exit(0);
}

##
## show left overs as a graph
##
printf("digraph \"%s packages\" {\n",
       $limit ? "out of date" : "installed");
printf("label = \"%s packages %s, generated by %s v%s, on %s\";\n",
       $limit ? "out of date" : "installed",
       @subgraph ? "subgraph (@subgraph)" : "graph",
       $iam, $version, scalar(localtime));
foreach $pkg (sort(bynum keys %vpkgs)) {
    $color = color($pkg);
    next if ($limit && $color eq "green");
    $label = $pkg;
    $label =~ s/(.*)-.*/$1/ if (!$versions);
    $label = "($ord{$pkg}) $label" if ($order);
    $label = "$where{$pkg}\\n$label" if ($locations);
    $label .= "\\n$need{$pkg}$forced{$pkg}" if ($need{$pkg});
    if ($vuln{$pkg}) {
	$label .= "\\n(no update available)" if (!$need{$pkg});
	$label .= "\\n[$vuln{$pkg}]";
    }
    $suffix = "\t// \#$ord{$pkg}, group $num{$pkg}, " .
	(exists($impactof{$pkg}) ? "impact $impactof{$pkg}, " : "") .
	scalar(@{$num[$num{$pkg}]}) . " members, $pkgcnt pkgs";
    $suffix .= ", LEAF" if ($ord{$pkg} == 1);

    ##
    ## scan the cluster list, but in the opposite order so in the case
    ## of pkgs with a common "multi-token" prefix, we only emit the
    ## one with the longest name.  we have to prepend the names to a
    ## buffer so that they end up being printed in the reverse of
    ## discovery order, so that we end up with the "least-specific"
    ## subgroup announced first.
    ##
    ($a = $pkg) =~ s/_/-/g;
    $b = 1;
    $cluster = "";
    while ($group && $a =~ s/-[^-]+-?$/-/) {
	next if ($clusters{$a} == $b);
	$b = $clusters{$a};
	$cluster = sprintf("subgraph \"cluster_%s\" {\n", substr($a, 0, -1)) .
	    sprintf("label = \"%s (%d)\";\n", substr($a, 0, -1), $b) .
		$cluster;
    }
    print($cluster);
    printf("\"%s\" [color=\"%s\",label=\"%s\"];$suffix\n", $pkg,
	   $usecolor ? $color : "black", $label);
    $cluster =~ s/label = .*\n//g;
    $cluster =~ s/.+\{/\}/g;
    print($cluster);
    @reqs = sort(keys %{$req{$pkg}});
    $suffix =~ s/, LEAF$//;
    $suffix .= ", EDGE";
    foreach $req (@reqs) {
	$color = color($req);
	next if ($limit && $color eq "green");
	printf("\"%s\" -> \"%s\" [color=\"%s\"];$suffix\n", $req, $pkg,
	       $usecolor ? $color : "black");
    }
}
print("}\n");

##
## print sh(1) style commands to handle work on a given package, or
## just the package name if $simple is set
##
sub print_package {
    foreach (@_) {
	printf("( pkg_info -qe %s || ", /(.*)-.*/) if ($exists && !$simple);
	if ($simple) {
	    print($_);
	}
	elsif ($pkgadd) {
	    printf("( pkg_add %s.tgz", ($need{$_} || $_));
	}
	else {
	    print("( cd $pkgsrcdir/$where{$_} && $make $target");
	    print(" && $make $clean") if ($clean);
	}
	if (!$simple) {
	    print(" )") if ($exists);
	    print(" ) &&");
	}
	print("\n");
    }
}

##
## find all dependencies above or below a given node
##
sub recurse {
    my(@list, @new, $map);
    @list = ();
    $map = shift;
    foreach (@_) {
	@new = keys %{$map->{$_}};
	push(@list, @new, recurse($map, @new));
    }
    uniq(sort(@list));
}

##
## canonicalize a pkg name based on what we have installed
##
sub canonicalize {
    my($canon, $pkg);

    foreach $pkg (@_) {
	# attempt to find actual pkg, first by argument given...
	($canon) = grep($pkg eq $_, @pkgs);

	# ...then by comparing against the internal list sans version numbers
	($canon) = grep(($a = $_) =~ s/(.*)-.*/$1/ && $pkg eq $a, @pkgs)
	    if (!defined($canon));

	die("package '$pkg' not found\n")
	    if (!defined($canon));

	$pkg = $canon;
    }

    @_;
}

##
## lowest group number of a set of packages
##
sub number {
    my($n, $pkg);
    $n = 0;
    foreach $pkg (@_) {
	$n = $num{$pkg} if ($n == 0 || $num{$pkg} < $n);
    }
    $n + 0;
}

##
## pick a color based on the color of the dependencies
##
sub color {
    my($pkg) = @_;
    if ($color{$pkg}) {
	$color{$pkg};
    }
    else {
	my($req, @reqs, $color);
	@reqs = sort(keys %{$req{$pkg}});
	@reqs = (@reqs, recurse(\%req, @reqs));
	$color = "green";
	foreach $req (@reqs) {
	    if ($color{$req} eq "red") {
		return "orange"; 
	    }
	    elsif ($color{$req} eq "purple") {
		$color = "blue";
	    }
	}
	$color;
    }
}

##
## bynum - higher numbers come last
##
sub bynum {
    return $num{$a} <=> $num{$b} ||
	$a cmp $b;
}

##
## byord - higher orders come first
##
sub byord {
    return $ord{$b} <=> $ord{$a} ||
	$b cmp $a;
}

##
## order - the order of a pkg is one higher than anything below it  
##
sub order {
    my($n, @pkgs) = @_;
    my($pkg);
    foreach $pkg (@pkgs) {
	$ord{$pkg} = $n if ($ord{$pkg} <= $n);
	order($n + 1, sort(keys %{$req{$pkg}}));
    }
}

##
## uniq - eliminate adjacent duplicate entries in an array
##
sub uniq {
    my($i);
    for ($i = 0; $i < $#_; ) {
	if ($_[$i] eq $_[$i + 1]) {
	    splice(@_, $i, 1);
	}
	else {
	    $i++;
	}
    }
    @_;
}

##
## impactof - impact of pkg delete/rebuild is the longest path (either
## up or down the tree) that encompasses all things that need
## rebuilding
##
sub impactof {
    my ($impact, $pkg) = @_;
    my (@in, @out);

    # if we already know or it's dead-simple, get out early
    return $impactof{$pkg} if (exists($impactof{$pkg}));
    return $impactof{$pkg} = 0 if (color($pkg) eq "green");

    # starting with the given pkg, repeatedly look up and down the
    # tree for connected pkgs that also require a rebuild
    @out = ($pkg);
    do {
	@in = @out;
	@out = ($pkg);
	push(@out, grep(color($_) ne "green", recurse(\%dep, @in)));
	push(@out, grep(color($_) ne "green", recurse(\%req, @out)));
	@out = uniq(sort(byord @out));
    } while (@in != @out);

    # check to see if the set of related pkgs intersects with the set
    # we want to avoid and if so, mark this set as "too expensive"
    $a = "";
    if (@impact) {
	foreach $b (@impact) {
	    if (grep($_ eq $b, @out)) {
		$a = $b;
		$impact++;
		last;
	    }
	}
    }

    # if we didn't hit anything, the impact is the one less than the
    # highest ordered remotely connected pkg we found (the longest
    # path from the top to the bottom of the set to be rebuilt)
    $impact = $ord{$out[0]} - 1 if ($a eq "");
    @impactof{@in} = ($impact) x @in;

    $impactof{$pkg};
}
