# $NetBSD: buildlink2.mk,v 1.1 2002/08/31 02:42:42 wiz Exp $

.if !defined(LIBMPEG3_BUILDLINK2_MK)
LIBMPEG3_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libmpeg3
BUILDLINK_DEPENDS.libmpeg3?=		libmpeg3>=1.3nb2
BUILDLINK_PKGSRCDIR.libmpeg3?=	../../devel/libmpeg3

EVAL_PREFIX+=		BUILDLINK_PREFIX.libmpeg3=libmpeg3
BUILDLINK_PREFIX.LIBMPEG3_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libmpeg3=	include/mpeg3/*
BUILDLINK_FILES.libmpeg3+=	include/mpeg3/*/*
BUILDLINK_FILES.libmpeg3+=	lib/libmpeg3.*

.include "../../mk/pthread.buildlink2.mk"

BUILDLINK_TARGETS+=		libmpeg3-buildlink

libmpeg3-buildlink: _BUILDLINK_USE

.endif	# LIBMPEG3_BUILDLINK2_MK
