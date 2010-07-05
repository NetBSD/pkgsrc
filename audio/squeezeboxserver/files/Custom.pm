package Slim::Utils::OS::Custom;

# $NetBSD: Custom.pm,v 1.1.1.1 2010/07/05 00:54:46 cube Exp $

# Squeezebox Server Copyright 2001-2009 Logitech.
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License, 
# version 2.

use strict;
use FindBin qw($Bin);

use base qw(Slim::Utils::OS::Unix);

sub initSearchPath {
	my $class = shift;

	$class->SUPER::initSearchPath();

	my @paths = qw(@PREFIX@/libexec @PREFIX@/bin);

	Slim::Utils::Misc::addFindBinPaths(@paths);
}

=head2 dirsFor( $dir )

Return OS Specific directories.

Argument $dir is a string to indicate which of the Squeezebox Server directories we
need information for.

=cut

sub dirsFor {
	my ($class, $dir) = @_;

	my %pkgsrcdirs = (
		CONF => '@PKG_SYSCONFDIR@',
		SHARE => '@SBS_SHAREDIR@',
		LOG => '@SBS_LOGDIR@',
		PREFS => '@SBS_PREFSDIR@',
		CACHE => '@SBS_CACHEDIR@',
		BIN => '@PREFIX@/libexec',
		LIB => '@SBS_LIBDIR@',
	);

	my @dirs = ();
	
	if ($dir =~ /^(?:oldprefs|updates)$/) {

		push @dirs, $class->SUPER::dirsFor($dir);

	} elsif ($dir eq 'Bin') {

		push @dirs, $pkgsrcdirs{BIN}

	} elsif ($dir =~ /^(?:Firmware|Graphics|HTML|IR|MySQL|SQL)$/) {

		push @dirs, $pkgsrcdirs{SHARE} . "/$dir";

	} elsif ($dir =~ /^(?:strings|revision)$/) {

		push @dirs, $pkgsrcdirs{SHARE};

	} elsif ($dir eq 'Plugins') {
			
		push @dirs, $class->SUPER::dirsFor($dir);
		push @dirs, $pkgsrcdirs{LIB} . "/Plugins";
		
	} elsif ($dir eq 'libpath') {

		push @dirs, $pkgsrcdirs{LIB};

	# Because we use the system MySQL, we need to point to the right
	# directory for the errmsg. files. Default to english.
	} elsif ($dir eq 'mysql-language') {

		push @dirs, '@PREFIX@/share/mysql/english';

	} elsif ($dir =~ /^(?:types|convert)$/) {

		push @dirs, $pkgsrcdirs{CONF};

	} elsif ($dir =~ /^(?:prefs)$/) {

		push @dirs, $::prefsdir || $pkgsrcdirs{PREFS};

	} elsif ($dir eq 'log') {

		push @dirs, $::logdir || $pkgsrcdirs{LOG};

	} elsif ($dir eq 'cache') {

		push @dirs, $::cachedir || $pkgsrcdirs{CACHE};

	} elsif ($dir =~ /^(?:music|playlists)$/) {

		push @dirs, '';

	} else {

		warn "dirsFor: Didn't find a match request: [$dir]\n";
	}

	return wantarray() ? @dirs : $dirs[0];
}

1;
