# $NetBSD: bsd.checksum-vars.mk,v 1.3 2018/01/07 11:23:37 rillig Exp $
#
# This Makefile fragment is included separately by bsd.pkg.mk and
# defines some variables which must be defined earlier than where
# bsd.checksum.mk is included.
#
# The following variables may be set in a package Makefile:
#
#    DISTINFO_FILE is the path to file containing the checksums.
#
# Keywords: distinfo

DISTINFO_FILE?=		${PKGDIR}/distinfo

.if !empty(_CKSUMFILES)
USE_TOOLS+=	digest:bootstrap
.endif
