# $NetBSD: bsd.flavor-vars.mk,v 1.1 2006/06/03 23:11:42 jlam Exp $
#
# This Makefile fragment is included by bsd.prefs.mk and defines some
# variables which must be defined earlier than where bsd.flavor.mk
# is included.
#

# Default to the pkgsrc-package flavor.
PKG_FLAVOR?=	pkg

.sinclude "${PKGSRCDIR}/mk/flavor/${PKG_FLAVOR}/flavor-vars.mk"
