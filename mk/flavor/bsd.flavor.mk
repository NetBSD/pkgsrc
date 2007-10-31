# $NetBSD: bsd.flavor.mk,v 1.2 2007/10/31 12:07:13 rillig Exp $
#
# This Makefile fragment is included by bsd.pkg.mk and pulls in the correct
# target and variable overrides for the selected package system flavor.
#

.include "${PKG_FLAVOR}/flavor.mk"
