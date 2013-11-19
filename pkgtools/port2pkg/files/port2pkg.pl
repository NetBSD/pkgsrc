#!/usr/bin/env perl
#
# $NetBSD: port2pkg.pl,v 1.21 2013/11/19 10:46:06 tron Exp $
#

use Getopt::Std;

$^W=1;
use strict;
use vars qw($opt_m);
my($maintainer) = "pkgsrc-users\@NetBSD.org";
my($makefile, $master_site_subdir, $extract_cmd);
my($portsdir, $pkgdir);
my($namespace, $portname, $portversion, $distname,
   $pkgname, $pkgnameprefix, $pkgnamesuffix);
my(@man, @cat);

&usage_and_exit() if (! &getopts('m:'));
$|=1;

$portsdir = shift;
$pkgdir = shift;
&usage_and_exit() if (! $portsdir || ! $pkgdir);

$maintainer = $opt_m if ($opt_m);
die "$portsdir: $!\n" if (! -d "$portsdir");
if (! -d "$pkgdir") {
	if (mkdir($pkgdir, 0755) == 0) {
		die "$pkgdir: $!\n";
	}
}

system("${GTAR} cCf $portsdir - .|${GTAR} xCf $pkgdir -");

&fix_new_ports();
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

sub fix_new_ports {
	my (@allfiles);
	my ($fn, $dn);
	if (-f "$pkgdir/pkg-comment") {
	    rename("$pkgdir/pkg-comment", "$pkgdir/COMMENT") ||
	    warn("can't copy $pkgdir/pkg-comment to $pkgdir/COMMENT");
	}
	rename("$pkgdir/pkg-descr", "$pkgdir/DESCR") ||
	    warn("can't copy $pkgdir/pkg-descr to $pkgdir/DESCR");
	if (-f "$pkgdir/pkg-message") {
	    rename("$pkgdir/pkg-message", "$pkgdir/MESSAGE") ||
	    warn("can't copy $pkgdir/pkg-message to $pkgdir/MESSAGE");
	}
	foreach $fn (<$pkgdir/pkg-plist*>) {
	    $dn = $fn;
	    $dn =~ s|.*pkg-plist|PLIST|;
	    rename("$fn", "$pkgdir/$dn") ||
		warn("can't copy $fn to $pkgdir/$dn");
	}
	unlink <$pkgdir/files/patch*>;
	unlink("$pkgdir/distinfo");
	mkdir("$pkgdir/patches",0777);
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
		if (/^PORTNAME\?*=(\s*)(.*)/) {
			$namespace = $1;
			$portname = $2;
		} elsif (/^PORTVERSION\?*=\s*(.*)/) {
			$portversion = $1;
		} elsif (/^PKGNAMEPREFIX\?*=\s*(.*)/) {
			$pkgnameprefix = $1;
		} elsif (/^PKGNAMESUFFIX\?*=\s*(.*)/) {
			$pkgnamesuffix = $1;
		} elsif (/^DISTNAME\?*=\s*(.*)/) {
			$distname = $1;
		} elsif (/^MASTER_SITE_SUBDIR\?*=\s*(.*)/) {
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

	if (defined($distname)) {
		$distname =~ s/\${PORTNAME}/$portname/;
		$distname =~ s/\${PORTVERSION}/$portversion/;

		if ($distname ne "$portname-$portversion") {
			$pkgname = "$portname-$portversion";
		}
	} else {
		$distname = "$portname-$portversion";
	}
	if (defined($pkgnameprefix)) {
		$pkgname = $distname unless (defined($pkgname));
		$pkgname = $pkgnameprefix . $pkgname;
	}
	if (defined($pkgnamesuffix)) {
		$pkgname = $distname unless (defined($pkgname));
		$pkgname .= $pkgnamesuffix;
	}
}

sub conv_Makefile {
	open(PORTS, "$portsdir/Makefile")
		|| die "$portsdir/Makefile: $!\n";
	open(PKG, ">$pkgdir/Makefile")
		|| die "$pkgdir/Makefile: $!\n";

	print PKG "# \$Net" . "BSD\$\n";

	# header
	while (<PORTS>) {
		last if (! /^\#/);

		if (/\$FreeBSD(: .*) \$/ || /\$Id(: .*) \$/) {
			print PKG "\# FreeBSD Id$1\n";
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
			next if ($remove);
		} else {
			$nextline = 0;
			if ($remove) {
				$remove = 0;
				next;
			}
		}

		s|^\.include <bsd.port.pre.mk>|.include \"../../mk/bsd.prefs.mk\"|;
		s|^\.include <bsd.port.mk>|.include \"../../mk/bsd.pkg.mk\"|;
		s|^FETCH_(DEPENDS)|BUILD_$1|;
		s|^LIB_(DEPENDS)|$1|;
		s|\$\{PORTNAME\}|\${PKGBASE}|g;
		s|\$\{PORTSDIR\}|../..|g;
		s|PLIST_SUB|PLIST_SUBST|;
		s|^USE_GMAKE\?*=\s*yes|USE_TOOLS+=\tgmake|;

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
		    /(\/usr\/X11R6)/ ||
		    /(ldconfig)/i ||
		    /(MASTERDIR)/ ||
		    /(.*cat.*MESSAGE.*)/i) {
			print "WARN: found \"$1\"\n";
		}

		if (/^PORTVERSION/ ||
		    /^PKGNAMEPREFIX/ ||
		    /^PKGNAMESUFFIX/ ||
		    /^DISTNAME/ ||
		    /^MAN(.)\?*=/ ||
		    /^CAT(.)\?*=/ ||
		    /^MASTER_SITE_SUBDIR/ ||
		    /^EXTRACT_BEFORE_ARGS/ ||
		    /^EXTRACT_AFTER_ARGS/) {
			$remove = 1 if ($nextline);
		} elsif (/^PORTNAME/) {
			print PKG "DISTNAME=$namespace$distname\n";
			print PKG "PKGNAME=$namespace$pkgname\n" if defined($pkgname);
			$remove = 1 if ($nextline);
		} elsif (/^(EXTRACT_CMD\?*=)/) {
			print PKG "$1\t$extract_cmd\n";
			$remove = 1 if ($nextline);
		} elsif (/^(MAINTAINER\?*=)/) {
			print PKG "$1\t$maintainer\n";
			$remove = 1 if ($nextline);

			open(DESCR, "$pkgdir/DESCR")
				|| die "$pkgdir/DESCR: $!\n";
			while (<DESCR>) {
				chop;
				if (/^WWW:[\s]*(.*)/) {
					print PKG "HOMEPAGE=\t$1\n";
				}
			}
			close(DESCR);
			if ( -f "$pkgdir/COMMENT") {
				open(COMMENT, "$pkgdir/COMMENT")
					|| die "$pkgdir/COMMENT: $!\n";
				while (<COMMENT>) {
					chomp;
					print PKG "COMMENT=\t$_\n";
				}
				close(COMMENT);
				unlink("$pkgdir/COMMENT");
			}
		} elsif ($noportdocs || /^\.if.*NOPORTDOCS/) {
			if (/^\.if/) {
				$noportdocs++;
				print PKG $_ if ($noportdocs > 2);
			} elsif (/^\.endif/) {
				$noportdocs--;
				print PKG $_ if ($noportdocs > 2);
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
		next if (!defined(eval "\$$category\[\$i\]"));
			foreach my $item (sort(split(/[ \t\n]+/,
			    eval "\$$category\[\$i\]"))) {
				print $FILE "$category/$category$i/$item\n";
		}
	}
}

sub conv_PLIST {
	my ($file, $plist);
	return 0 if (!opendir(PKGDIR, "$pkgdir"));
	while ($plist = readdir(PKGDIR)) {
		next if (!($plist =~ /^PLIST/));

		open(OLDPLIST, "$pkgdir/$plist")
		    || die "$pkgdir/$plist: $!\n";
		open(NEWPLIST, ">$pkgdir/new.$plist")
			|| die "$pkgdir/new.$plist: $!\n";

		print NEWPLIST "\@comment \$"."NetBSD\$\n";
		my ($cat_added, $man_added);
		while (<OLDPLIST>) {
			s|\%\%([^\%]+)\%\%|\${$1}|g;
			next if (/^\@.*ldconfig/);
			if (defined($cat_added) && $cat_added == 0 && /^[d-z]/){
				&add_manual(*NEWPLIST, "cat");
				$cat_added++;
			}
			if (defined($man_added) && $man_added == 0 && /^[n-z]/){
				&add_manual(*NEWPLIST, "man");
				$man_added++;
			}

			print NEWPLIST $_;
		}
		if (defined($cat_added) && $cat_added == 0)
			{&add_manual(*NEWPLIST, "cat");}
		if (defined($man_added) && $man_added == 0)
			{&add_manual(*NEWPLIST, "man");}

		close(NEWPLIST);
		close(OLDPLIST);
		rename("$pkgdir/new.$plist", "$pkgdir/$plist");
	}
	closedir(PKGDIR);
}

sub add_NetBSD_ID {
	my ($patch);
	if (open(MD5, "$portsdir/files/md5")
	    || open(MD5, "$portsdir/distinfo")) {
		open(NMD5, ">$pkgdir/distinfo")
			|| die "$pkgdir/distinfo: $!\n";
		print NMD5 "\$"."NetBSD\$\n\n";
		while (<MD5>) {
			print NMD5 $_;
		}
		close(NMD5);
		close(MD5);
	}

	opendir(PATCHDIR, "$portsdir/patches") ||
	    opendir(PATCHDIR, "$portsdir/files") ||
		return 0;
	while ($patch = readdir(PATCHDIR)) {
		if ($patch eq "\." || $patch eq "\.."
			|| $patch eq "CVS") {next;}
		if (open(PATCH, "$portsdir/patches/$patch")
		    || open(PATCH, "$portsdir/files/$patch")) {
			open(NPATCH, ">$pkgdir/patches/$patch")
				|| die "$pkgdir/patches/$patch: $!\n";
			print NPATCH "\$"."NetBSD\$\n\n";
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
