# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/05/11 02:09:14 jlam Exp $
#
# This Makefile fragment is included by packages that use mng.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.mng to the dependency pattern
#     for the version of mng desired.
# (2) Include this Makefile fragment in the package Makefile.

.if !defined(MNG_BUILDLINK2_MK)
MNG_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.buildlink2.mk"

BUILDLINK_DEPENDS.mng?=	mng>=1.0.0
DEPENDS+=		${BUILDLINK_DEPENDS.mng}:../../graphics/mng

BUILDLINK_PREFIX.mng=	${LOCALBASE}
BUILDLINK_FILES.mng=	include/libmng.h
BUILDLINK_FILES.mng+=	include/libmng_conf.h
BUILDLINK_FILES.mng+=	include/libmng_types.h
BUILDLINK_FILES.mng+=	lib/libmng.*

.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/lcms/buildlink2.mk"

BUILDLINK_TARGETS+=	mng-buildlink

mng-buildlink: _BUILDLINK_USE

.endif	# MNG_BUILDLINK2_MK
