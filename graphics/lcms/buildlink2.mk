# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/05/11 02:09:13 jlam Exp $
#
# This Makefile fragment is included by packages that use lcms.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.lcms to the dependency pattern
#     for the version of lcms desired.
# (2) Include this Makefile fragment in the package Makefile.

.if !defined(LCMS_BUILDLINK2_MK)
LCMS_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.buildlink2.mk"

BUILDLINK_DEPENDS.lcms?=	lcms>=1.06
DEPENDS+=	${BUILDLINK_DEPENDS.lcms}:../../graphics/lcms

BUILDLINK_PREFIX.lcms=	${LOCALBASE}
BUILDLINK_FILES.lcms=	include/lcms/*
BUILDLINK_FILES.lcms+=	lib/liblcms.*

BUILDLINK_TARGETS+=	lcms-buildlink

lcms-buildlink: _BUILDLINK_USE

.endif	# LCMS_BUILDLINK2_MK
