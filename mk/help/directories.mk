# $NetBSD: directories.mk,v 1.2 2007/01/12 07:47:16 rillig Exp $
#
# This file contains some short documentation on the directories that
# are used within pkgsrc.

# PREFIX
#	This is the directory where the package should install its
#	files. The actual value depends on the variables
#	PKG_INSTALLATION_TYPE, USE_X11BASE and USE_CROSSBASE.
#
#	Tags: read-only, system-defined, non-overridable, etc.
#
#	See also:
#		CROSSBASE,
#		INSTALLATION_PREFIX,
#		LOCALBASE,
#		X11PREFIX,
#		PKG_INSTALLATION_TYPE.
#

# LOCALBASE
#	This is the directory where all packages are usually installed.
#	It is set by the user, and packages must not modify it.
#

# PKG_SYSCONFBASE
# PKG_SYSCONFDIR.*
#	These variables may be set in mk.conf to control where the
#	configuration files are put.
#
#	See also: guide:faq.html#faq.conf
#

# PKG_SYSCONFVAR
#	This variable can be set by packages to select the variable
#	which can then be overridden in mk.conf to change the directory
#	where the configuration files go.
#
#	Default value: ${PKGBASE}
#

# PKG_SYSCONFDIR
#	This is the directory where the current package should install
#	its configuration files. It may be changed by the package to
#	point to a subdirectory of PKG_SYSCONFBASE.
#

# TODO:PKG_SYSCONFDEPOTBASE
# TODO:PKG_SYSCONFBASEDIR
#
