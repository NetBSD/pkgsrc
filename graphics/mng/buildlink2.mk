# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 18:39:17 jlam Exp $

.if !defined(MNG_BUILDLINK2_MK)
MNG_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		mng
BUILDLINK_DEPENDS.mng?=		mng>=1.0.0
BUILDLINK_PKGSRCDIR.mng?=	../../graphics/mng

EVAL_PREFIX+=	BUILDLINK_PREFIX.mng=mng
BUILDLINK_PREFIX.mng_DEFAULT=	${LOCALBASE}
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
