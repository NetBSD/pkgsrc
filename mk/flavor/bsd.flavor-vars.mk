# $NetBSD: bsd.flavor-vars.mk,v 1.2 2008/01/04 01:46:27 rillig Exp $
#
# This Makefile fragment is included by bsd.prefs.mk and defines some
# variables which must be defined earlier than where bsd.flavor.mk
# is included.
#

# Default to the pkgsrc-package flavor.
PKG_FLAVOR?=	pkg

.sinclude "${PKG_FLAVOR}/flavor-vars.mk"
