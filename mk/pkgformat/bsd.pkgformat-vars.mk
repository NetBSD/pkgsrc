# $NetBSD: bsd.pkgformat-vars.mk,v 1.1 2011/10/15 00:23:09 reed Exp $
#
# This Makefile fragment is included by bsd.prefs.mk and defines some
# variables which must be defined earlier than where bsd.pkgformat.mk
# is included.
#

# Default to the pkgsrc package format.
PKG_FORMAT?=	pkg

.sinclude "${PKG_FORMAT}/pkgformat-vars.mk"
