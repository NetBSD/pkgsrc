# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/05/11 02:09:23 jlam Exp $
#
# This Makefile fragment is included by packages that use libmcrypt22.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.libmcrypt22 to the dependency pattern
#     for the version of GNU libmcrypt22 desired.
# (2) Include this Makefile fragment in the package Makefile.

.if !defined(LIBMCRYPT22_BUILDLINK2_MK)
LIBMCRYPT22_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.buildlink2.mk"

BUILDLINK_DEPENDS.libmcrypt22?=	libmcrypt22>=2.2.7
DEPENDS+=	${BUILDLINK_DEPENDS.libmcrypt22}:../../security/libmcrypt22

BUILDLINK_PREFIX.libmcrypt22=	${LOCALBASE}
BUILDLINK_FILES.libmcrypt22=	include/libmcrypt22/mcrypt.h
BUILDLINK_FILES.libmcrypt22+=	lib/libmcrypt22.*

BUILDLINK_TRANSFORM.libmcrypt22=	-e "s|include/libmcrypt22/|include/|g"
BUILDLINK_TRANSFORM+=			l:mcrypt:mcrypt22

BUILDLINK_TARGETS+=	libmcrypt22-buildlink

libmcrypt22-buildlink: _BUILDLINK_USE

.endif	# LIBMCRYPT22_BUILDLINK2_MK
