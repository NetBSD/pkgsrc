#!@PREFIX@/bin/perl

# Copyright (c) 2002, 2003 by Andrew Brown <atatat@netbsd.org>
# Absolutely no warranty.

# $NetBSD: pkgdepgraph.pl,v 1.5 2003/03/14 23:39:56 atatat Exp $
# pkgdepgraph: @DISTVER@

use strict;

use Getopt::Long;
Getopt::Long::Configure("bundling");
my(@opts, %opt);
my($iam, $version, $usecolor, $group, $locations, $order, $versions);
my($limit, $delete, $rebuild, $force, @outofdate, @update, $clean);
my($pkg_dbdir, $pkgsrcdir, $packages, $pkgadd);

$version = '@DISTVER@';
($iam = $0) =~ s:.*/::;
@opts = ('A', 'C', 'c', 'D', 'd=s', 'f', 'g', 'K=s', 'L', 'l', 'O=s',
	 'o', 'P=s', 'R', 't=s', 'U=s', 'v');
%opt = (
	'A' => \$pkgadd,
	# 'C' => implies "realclean", handled later
	# 'c' => implies "clean", handled later
	'D' => \$delete,
	'd' => \$pkg_dbdir,
	'f' => \$force,
	'g' => \$group,
	'K' => \$packages,
	'L' => \$limit,
	'l' => \$locations,
	'O' => \@outofdate,
	'o' => \$order,
	'P' => \$pkgsrcdir,
	'R' => \$rebuild,
	# 't' => goes to rebuild, handled later
	'U' => \@update,
	'v' => \$versions,
	);
die("usage: $iam [-ACcDfgLloRv] [-d pkg_dbdir] [-K packages] [-O package]\n",
    " " x (length($iam) + 8),
    "[-P pkgsrcdir] [-t target] [-U package] [data ...]\n")
    if (!GetOptions(\%opt, @opts));

$pkg_dbdir ||= $ENV{'PKG_DBDIR'} || "/var/db/pkg";
$pkgsrcdir ||= $ENV{'PKGSRCDIR'} || "/usr/pkgsrc";
$packages = $ENV{'PKG_PATH'} if (!$packages);
$packages = $ENV{'PACKAGES'} . "/All" if (!$packages && $ENV{'PACKAGES'});
$packages = $pkgsrcdir . "/packages/All" if (!$packages);
$rebuild &&= $opt{t} || "install";
$clean = "clean" if ($opt{c});
$clean = "CLEANDEPENDS=YES clean" if ($opt{C});

my(@pkgs, $pkg, $req, %req, @reqs, @rreqs);
my(%clusters, $cluster);
my(%where, $pkgcnt, $num, %num, @num, %ord, @ord, $suffix);
my(%color, $color, %vuln);
my(%need, $label);
my($recolor, @graph);

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
    $where{$pkg} = $pkg;
    open(R, "<$pkg_dbdir/$pkg/+BUILD_INFO") ||
	die("$pkg: +BUILD_INFO: $!\n");
    while (<R>) {
	if (/^PKGPATH\s*=\s*(\S+)/) {
	    $where{$pkg} = $1;
	    last;
	}
    }
    close(R);
    next if (!open(R, "<$pkg_dbdir/$pkg/+REQUIRED_BY"));
    while ($req = <R>) {
	chomp($req);
	$req{$req}->{$pkg} = 1;
    }
    close(R);
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
    @rreqs = recurse(@reqs);
    map(delete($req{$pkg}->{$_}), @rreqs);
}

##
## create a hash of clusters of package prefixes, with counts.  later,
## clusters that have more than one member can be marked as subgraphs.
##
## the outer map() iterates over each pkg name.  the inner map()
## breaks each pkg name up into tokens that end in either _ or - and
## loops over the resulting list, appending each one to $a.  for
## example:
##
##	pkg:	one_two-three-4.56
##	tokens:	one_     two-         three-
##	$a:	one_ one_two- one_two-three-
##
map({ $a = ""; map({ $a .= $_; $clusters{$a}++; } /([^-_]*[-_])/g); } @pkgs);

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
## that group.  the higher the order number, the earlier we need to
## assign them to a group.  the group numbers are arbitrary, and serve
## only to identify pkgs that belong to the same group.
##
$num = 1;
foreach $pkg (sort(byord @pkgs)) {
    my($pkgnum);
    @reqs = sort(keys %{$req{$pkg}});
    @rreqs = recurse(@reqs);
    $pkgnum = number($pkg, @reqs, @rreqs) || $num;
    foreach $req ($pkg, @reqs, @rreqs) {
	$num[$num{$req}]--;
	$num{$req} = $pkgnum;
	$num[$num{$req}]++;
    }
    $num++;
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
	    $need{$_} = "$_ (forced)";
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
    @update = uniq(sort(@update, recurse(@update)));

    if ($force) {
	foreach (@update) {
	    if ($color{$_} ne "red") {
		$color{$_} = "red";
		$need{$_} = "$_ (forced)";
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
## "delete" output, ordered with "least depended on" first
##
if ($delete) {
    map(print("$_\n"),
	reverse(sort(byord grep(color($_) ne "green", @pkgs))));
    exit(0);
}

##
## "rebuild" output for sh(1), with just leaves listed.  all the
## dependencies will be built "automagically" by the regular build
## mechanism.  if $add is set, emit commands for installing binary
## pkgs instead.
##
if ($rebuild) {
    printf("PKG_PATH=\"$packages\"\nexport PKG_PATH\n") if ($pkgadd);

    map($pkgadd ?
	printf("( pkg_info -qe %s || pkg_add %s.tgz ) &&\n",
	       /(.*)-.*/, ($need{$_} || $_)) :
	printf("( pkg_info -qe %s || ( cd %s && make %s%s )) &&\n",
	       /(.*)-.*/, "$pkgsrcdir/$where{$_}",
	       $rebuild, $clean ? " && make $clean" : ""),
	grep(color($_) ne "green" && $ord{$_} == 1, @pkgs));
    print("true\n");
    exit(0);
}

##
## show left overs as a graph
##
printf("digraph \"%s packages\" {\n",
       $limit ? "out of date" : "installed");
printf("label = \"%s packages graph, generated by %s v%s, on %s\";\n",
       $limit ? "out of date" : "installed",
       $iam, $version, scalar(localtime));
foreach $pkg (sort(bynum @pkgs)) {
    $color = color($pkg);
    next if ($limit && $color eq "green");
    $label = $pkg;
    $label =~ s/(.*)-.*/$1/ if (!$versions);
    $label = "($ord{$pkg}) $label" if ($order);
    $label = "$where{$pkg}\\n$label" if ($locations);
    $label .= "\\n$need{$pkg}" if ($need{$pkg});
    if ($vuln{$pkg}) {
	$label .= "\\n(no update available)" if (!$need{$pkg});
	$label .= "\\n[$vuln{$pkg}]";
    }
    $suffix = "\t// \#$ord{$pkg}, group $num{$pkg}, $num[$num{$pkg}] members, $pkgcnt pkgs";
    $suffix .= ", LEAF" if ($ord{$pkg} == 1);

    ##
    ## scan the cluster list, but in the opposite order so in the case
    ## of pkgs with a common "multi-token" prefix, we only emit the
    ## one with the longest name.  we have to prepend the names to a
    ## buffer so that they end up being printed in the reverse of
    ## discovery order, so that we end up with the "least-specific"
    ## subgroup announced first.
    ##
    $a = $pkg;
    $b = 1;
    $cluster = "";
    while ($group && $a =~ s/([-_])[^-_]+[-_]?$/$1/) {
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
## find all dependencies below a given node
##
sub recurse {
    my(@list, @new);
    @list = ();
    foreach (@_) {
	@new = keys %{$req{$_}};
	push(@list, @new, recurse(@new));
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
## lowest number of a graph
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
	@reqs = (@reqs, recurse(@reqs));
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
