# $NetBSD: bsd.checksum-vars.mk,v 1.4 2024/10/11 12:53:13 jperkin Exp $
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

.if !empty(_CKSUMFILES) && empty(TOOLS_PLATFORM.mktool)
USE_TOOLS+=	digest:bootstrap
.endif
