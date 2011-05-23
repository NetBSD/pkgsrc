#!/usr/bin/env perl
# $NetBSD: pkgdep.pl,v 1.3 2011/05/23 08:28:42 cheusov Exp $

require 'getopts.pl';
use strict;
$^W=1;
$|=1;

use vars qw($opt_I $opt_h $opt_e $opt_r $opt_v);
my (%pkgdir, %builddeps, %rundeps, %buildreqd, %runreqd, %printed);
my ($indexfile) = "@PKGSRCDIR@/INDEX";
my ($package, $match_pkgs);
my (%node, %arrow, $home_level);
my(%color);
$color{"D"} = "black";
$color{"B"} = "blue";
$color{"R"} = "red";

if (!&Getopts('I:herv') || $opt_h) {&usage_and_exit;}
if (defined($opt_I)) {$indexfile = $opt_I;}
$package = shift;
if (!defined($package)) {&usage_and_exit;}

open(INDEX, $indexfile) || die "$indexfile: $!\n";
while (<INDEX>) {
	my (@data) = split(/\|/);
	$data[1] =~ s/.*\/([^\/]+\/[^\/]+)$/$1/;
	$pkgdir{$data[0]} = $data[1];
	$builddeps{$data[0]} = $data[7];
	$rundeps{$data[0]} = $data[8];
}
close(INDEX);

%buildreqd = &mkreqd(%builddeps);
%runreqd = &mkreqd(%rundeps);

for (keys %pkgdir) {
	my ($match) = 0;
	if (defined($opt_e)) {
		if (/$package/ || $pkgdir{$_} =~ /$package/) {
			$match = 1;
		}
	} else {
		if ($_ eq $package || $pkgdir{$_} eq $package) {
			$match = 1;
		}
	}

	if ($match) {
		$match_pkgs .= " $_";
	}
}

if (!defined($match_pkgs)) {
	print "no such package \'$package\'\n";
	exit 1;
} else {
	$match_pkgs =~ s/^ //;
}

if (split(/ /, $match_pkgs) != 1) {
	print "\'$package\' matches the following packages.\n";
	for (split(/ /, $match_pkgs)) {
		if (!defined($pkgdir{$_})) {$_ = &searchpkg($_);}
		print "\t$_ [$pkgdir{$_}]\n";
	}
	exit 1;
}

if (!defined($opt_v)) {
	my ($pkg) = $match_pkgs;
	my (@pkglist) = $pkg;

	while ($#pkglist >= 0) {
		my ($p);
		($p, @pkglist) = @pkglist;
		if (defined($printed{$p})) {next;}

		print "\n$p [$pkgdir{$p}]\n";
		$printed{$p} = 1;
		@pkglist = (@pkglist,
			&printdeps($p, "build", %builddeps));
		@pkglist = (@pkglist, &printdeps($p, "run", %rundeps));
		@pkglist = (@pkglist,
			&printreqd($p, "build", %buildreqd));
		@pkglist = (@pkglist, &printreqd($p, "run", %runreqd));
	}
} else {
	my ($pkg) = $match_pkgs;
	my ($min);

	print "graph: {\n";
	print "title: \"Dependent graph of $pkg\"\n";

	$home_level = 0;
	&depends_search($home_level, "", "", $pkg);
	$min = 0;
	for (keys %node) {if ($node{$_} < $min) {$min = $node{$_};}}
	for (keys %node) {$node{$_} += -$min;}

	$home_level = $node{$pkg};
	&required_search($home_level, "", "", $pkg);

	for (keys %node) {
		print "node: { title: \"$_\"\tlevel: $node{$_}" .
			" label: \"$_\n$pkgdir{$_}\"}\n";
	}
	for (keys %arrow) {
		print "$arrow{$_}";
	}
	print "}\n";
}

sub usage_and_exit { 
	print <<EOF;
Usage: pkgdep [opts] package
  -I INDEX file path (default: $indexfile)
  -e match package by regular expression
  -r recursive
  -v output graph data for xvcg
EOF
	exit 1;
}

sub mkreqd {
	my (%deps) = @_;
	my (%reqd);
	for (keys %deps) {
		my ($p) = $_;
		for (split(/ /, $deps{$p})) {
			$_ =~ s/(\+)/\\\1/g;
			if (defined($reqd{$_})) {
				if (!($reqd{$_} =~ /$_/)) {
					$reqd{$_} .= " " . $p;
				}
			} else {
				$reqd{$_} .= $p;
			}
		}
	}
	%reqd;
}

sub searchpkg {
	my ($pkg) = @_;
	$pkg =~ s/\*/.\*/;
	$pkg =~ s/-[^-]+/-.\*/;
	for (keys %pkgdir) {
		if ($_ =~ /$pkg/) {
			$pkg = $_;
			last;
		}
	}
	$pkg;
}

sub printdeps {
	my ($pkg, $depname, %deps) = @_;
	my (@rpkg);

	print "\t$depname depends on:\n";
	if (defined($deps{$pkg}) && $deps{$pkg} ne "") {
		for (sort split(/ /, $deps{$pkg})) {
			if (!defined($pkgdir{$_})) {$_ = &searchpkg($_);}
			print "\t\t$_ [$pkgdir{$_}]\n";
			if ($opt_r) {@rpkg = (@rpkg, $_);}
		}
	} else {
		print "\t\t(none)\n";
	}
	@rpkg;
}

sub printreqd {
	my ($pkg, $reqname, %reqd) = @_;
	my (@rpkg);

	print "\t$reqname required by:\n";
	if (defined($reqd{$pkg}) && $reqd{$pkg} ne "") {
		for (sort split(/ /, $reqd{$pkg})) {
			if (!defined($pkgdir{$_})) {$_ = &searchpkg($_);}
			print "\t\t$_ [$pkgdir{$_}]\n";
			if ($opt_r) {@rpkg = (@rpkg, $_);}
		}
	} else {
		print "\t\t(none)\n";
	}
	@rpkg;
}

sub depends_search {
	my ($level, $from, $type, $p) = @_;
	my (%types);

	if ($from ne "") {
		$arrow{"$from:$p"} =
			"edge: { sourcename: \"$from\" targetname: \"$p\"" .
			" color: $color{$type}}\n";
	}

	if (defined($node{$p})) {
		if ($level < $node{$p}) {
			$node{$p} = $level;
		}
		return;
	}
	$node{$p} = $level;

	if ($home_level - $level <= 1) {
		%types = &mktypes($builddeps{$p}, $rundeps{$p});
		for (sort(keys %types)) {
			&depends_search($level - 1, $p, $types{$_}, $_);
		}
	}

	if ($opt_r) {
		%types = &mktypes($buildreqd{$p}, $runreqd{$p});
		for (sort(keys %types)) {
			&required_search($level + 1, $p, $types{$_}, $_);
		}
	}
}

sub required_search {
	my ($level, $from, $type, $p) = @_;
	my (%types);

	if ($from ne "") {
		$arrow{"$p:$from"} =
			"edge: { sourcename: \"$p\" targetname: \"$from\"" .
			" color: $color{$type}}\n";

		if (defined($node{$p})) {
			if ($level > $node{$p}) {
				$node{$p} = $level;
				&level_fit($level, $p);
			}
			return;
		}
		$node{$p} = $level;
		&level_fit($level, $p);
	}

	if ($level - $home_level <= 1) {
		%types = &mktypes($buildreqd{$p}, $runreqd{$p});
		for (sort(keys %types)) {
			&required_search($level + 1, $p, $types{$_}, $_);
		}
	}

	if ($opt_r) {
		%types = &mktypes($builddeps{$p}, $rundeps{$p});
		for (sort(keys %types)) {
			&depends_search($level - 1, $p, $types{$_}, $_);
		}
	}
}

sub mktypes {
	my ($build, $run) = @_;
	my (%types);
	if (defined($build)) {
		for (split(/ /, $build)) {
			if (!defined($pkgdir{$_})) {$_ = &searchpkg($_);}
			if (!defined($run) || $run =~ /$_/) {$types{$_} = "D";}
			else {$types{$_} = "B";}
		}
	}
	if (defined($run)) {
		for (split(/ /, $run)) {
			if (!defined($pkgdir{$_})) {$_ = &searchpkg($_);}
			if (!defined($build) || $build =~ /$_/)
			    {$types{$_} = "D";}
			else {$types{$_} = "R";}
		}
	}
	%types;
}

sub level_fit {
	my ($level, $p) = @_;

	if (!defined($node{$p})) {return;}
	if ($node{$p} < $level) {$node{$p} = $level;}

	if ($buildreqd{$p}) {
		for (sort(split(/ /, $buildreqd{$p}))) {
			&level_fit($level + 1, $_);
		}
	}
	if ($runreqd{$p}) {
		for (sort(split(/ /, $runreqd{$p}))) {
			&level_fit($level + 1, $_);
		}
	}
}

exit 0;
