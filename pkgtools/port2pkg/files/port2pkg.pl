#!/usr/bin/env perl
#
# $NetBSD: port2pkg.pl,v 1.1.1.1 1999/07/27 11:33:06 sakamoto Exp $
#

require 'getopts.pl';
$^W=1;
use strict;
use vars qw($opt_m);
my($maintainer) = "packages\@netbsd.org";
my($makefile,$master_site_subdir,$extract_cmd);
my($portsdir, $pkgdir);
my(@man, @cat);

if (! &Getopts('m:')) {&usage_and_exit();}
$|=1;

$portsdir = shift;
$pkgdir = shift;
if (! $portsdir || ! $pkgdir) {&usage_and_exit();}

if ($opt_m) {$maintainer = $opt_m;}
if (! -d "$portsdir") {die "$portsdir: $!\n";}
if (! -d "$pkgdir") {
	if (mkdir($pkgdir, 0755) == 0) {
		die "$pkgdir: $!\n";
	}
}

system("tar cCf $portsdir - .|tar xCf $pkgdir -");

&read_Makefile();
&conv_Makefile();
&conv_PLIST();
&add_NetBSD_ID();

system("(cd $pkgdir; pkglint)");
0;

sub usage_and_exit {
	print "port2pkg [-m maintainer] portsdir pkgdir\n";
	exit;
}

sub read_Makefile {
	open(PORTS, "$portsdir/Makefile")
		|| die "$portsdir/Makefile: $!\n";
	while (<PORTS>) {
		if (/\\$/) {
			chop;
			chop;
		}
		$makefile .= $_;
	}
	close(PORTS);

	my ($extract_before_args, $extract_after_args);
	foreach my $line (split(/\n/, $makefile)) {
		$_ = $line;
		if (/^MASTER_SITE_SUBDIR\?*=\s*(.*)/) {
			$master_site_subdir = $1;
			if (!($master_site_subdir =~ /\/$/)) {
				$master_site_subdir .= "/";
			}
		} elsif (/^MAN(.)\?*=\s*(.*)/) {
			$man[$1] .= $2;
		} elsif (/^CAT(.)\?*=\s*(.*)/) {
			$cat[$1] .= $2;
		} elsif (/^EXTRACT_CMD\?*=\s*(.*)/) {
			$extract_cmd = $1;
		} elsif (/^EXTRACT_BEFORE_ARGS\?*=\s*(.*)/) {
			$extract_before_args = $1;
		} elsif (/^EXTRACT_AFTER_ARGS\?*=\s*(.*)/) {
			$extract_after_args = $1;
		}
	}

	if (defined($extract_cmd) && $extract_cmd ne "") {
		if ($extract_before_args ne "") {
			$extract_before_args = " $extract_before_args";
		}
		if ($extract_after_args ne "") {
			$extract_after_args = " $extract_after_args";
		}
		$extract_cmd = "$extract_cmd$extract_before_args" .
			" \${DOWNLOADED_DISTFILE}$extract_after_args";
	}
}

sub conv_Makefile {
	open(PORTS, "$portsdir/Makefile")
		|| die "$portsdir/Makefile: $!\n";
	open(PKG, ">$pkgdir/Makefile")
		|| die "$pkgdir/Makefile: $!\n";

	print PKG "# \$NetBSD\$\n";

	# header
	while (<PORTS>) {
		if (! /^\#/) {last;}

		if (/\$(Id: .*)/) {
			print PKG "\# FreeBSD $1\n";
		} else {
			print;
		}
	}
	print PKG;

	# body
	my ($nextline, $remove, $master_sites, $noportdocs);
	while (<PORTS>) {
		if (/\\$/) {
			$nextline++;
			if ($remove) {
				next;
			}
		} else {
			$nextline = 0;
			if ($remove) {
				$remove = 0;
				next;
			}
		}

		s|^\.include <bsd.port.mk>|.include \"../../mk/bsd.pkg.mk\"|;
		s|^FETCH_(DEPENDS)|BUILD_$1|;
		s|^LIB_(DEPENDS)|$1|;
		s|\$\{PORTSDIR\}|../..|g;

		if (defined($master_site_subdir) &&
		    $master_site_subdir ne "" &&
		    ($master_sites || /^MASTER_SITES\?*=/)) {
			s|([^L][^O][^C][^A][^L])\}|$1:=$master_site_subdir}|g;

			if ($nextline) {
				$master_sites = 1;
			} else {
				$master_sites = 0;
			}
		}

		if (/(\/usr\/local)/ ||
		    /(ldconfig)/i ||
		    /(MASTERDIR)/ ||
		    /(.*cat.*MESSAGE.*)/i) {
			print "WARN: found \"$1\"\n";
		}

		if (/^MAN(.)\?*=/ ||
		    /^CAT(.)\?*=/ ||
		    /^MASTER_SITE_SUBDIR/ ||
		    /^EXTRACT_BEFORE_ARGS/ ||
		    /^EXTRACT_AFTER_ARGS/) {
			if ($nextline) {
				$remove = 1;
			}
		} elsif (/^(EXTRACT_CMD\?*=)/) {
			print PKG "$1\t$extract_cmd\n";
			if ($nextline) {
				$remove = 1;
			}
		} elsif (/^(MAINTAINER\?*=)/) {
			print PKG "$1\t$maintainer\n";
			if ($nextline) {
				$remove = 1;
			}
		} elsif ($noportdocs || /^\.if.*NOPORTDOCS/) {
			if (/^\.if/) {
				$noportdocs++;
				if ($noportdocs > 2) {print PKG $_;}
			} elsif (/^\.endif/) {
				$noportdocs--;
				if ($noportdocs > 2) {print PKG $_;}
			} else {
				print PKG $_;
			}
		} else {
			print PKG $_;
		}
	}

	close(PORTS);
	close(PKG);
}

sub add_manual {
	my ($FILE, $category) = @_;

	for (my $i = 1; $i <= 8; $i++) {
		if (!defined(eval "\$$category\[\$i\]")) {next;}
			foreach my $item (sort(split(/[ \t\n]+/,
			    eval "\$$category\[\$i\]"))) {
				print $FILE "$category/$category$i/$item\n";
		}
	}
}

sub conv_PLIST {
	my ($file, $plist);
	if (opendir(PKGDIR, "$portsdir/pkg") == 0) {return 0;}
	while ($plist = readdir(PKGDIR)) {
		if (!($plist =~ /^PLIST/)) {next;}

		open(PORTS, "$portsdir/pkg/$plist")
			|| die "$portsdir/pkg/$plist: $!\n";
		open(PKG, ">$pkgdir/pkg/$plist")
			|| die "$pkgdir/pkg/$plist: $!\n";

		print PKG "\@comment \$NetBSD\$\n";
		my ($cat_added, $man_added);
		while (<PORTS>) {
			if (/^\@.*ldconfig/) {next;}
			if (defined($cat_added) && $cat_added == 0 && /^[d-z]/){
				&add_manual(*PKG, "cat");
				$cat_added++;
			}
			if (defined($man_added) && $man_added == 0 && /^[n-z]/){
				&add_manual(*PKG, "man");
				$man_added++;
			}

			print PKG $_;
		}
		if (defined($cat_added) && $cat_added == 0)
			{&add_manual(*PKG, "cat");}
		if (defined($man_added) && $man_added == 0)
			{&add_manual(*PKG, "man");}

		close(PKG);
		close(PORTS);
	}
	closedir(PKGDIR);
}

sub add_NetBSD_ID {
	my ($patch);
	if (open(MD5, "$portsdir/files/md5")) {
		open(NMD5, ">$pkgdir/files/md5")
			|| die "$pkgdir/files/md5: $!\n";
		print NMD5 "\$NetBSD\$\n\n";
		while (<MD5>) {
			print NMD5 $_;
		}
		close(NMD5);
		close(MD5);
	}

	if (opendir(PATCHDIR, "$portsdir/patches") == 0) {return 0;}
	while ($patch = readdir(PATCHDIR)) {
		if ($patch eq "\." || $patch eq "\.."
			|| $patch eq "CVS") {next;}
		if (open(PATCH, "$portsdir/patches/$patch")) {
			open(NPATCH, ">$pkgdir/patches/$patch")
				|| die "$pkgdir/patches/$patch: $!\n";
			print NPATCH "\$NetBSD\$\n\n";
			while (<PATCH>) {
				if (/(FreeBSD)/i ||
				    /(#!.*perl)/) {
					print "WARN: $pkgdir/patches/" .
					  "$patch includes \"$1\".\n";
				}
				print NPATCH $_;
			}
			close(NPATCH);
			close(PATCH);
		}
	}
	closedir(PATCHDIR);
}
