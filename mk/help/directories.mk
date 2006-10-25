# $NetBSD: directories.mk,v 1.1 2006/10/25 08:39:29 rillig Exp $
#
# This file contains some short documentation on the directories that
# are used within pkgsrc.

# PREFIX
#	This is the directory where the package should install its
#	files. In special situations, this variable may be set to a
#	subdirectory of LOCALBASE, but this is usually not needed.
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
