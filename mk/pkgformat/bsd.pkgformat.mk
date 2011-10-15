# $NetBSD: bsd.pkgformat.mk,v 1.1 2011/10/15 00:23:09 reed Exp $
#
# This Makefile fragment is included by bsd.pkg.mk and pulls in the correct
# target and variable overrides for the selected package system format.
#

.include "${PKG_FORMAT}/pkgformat.mk"
