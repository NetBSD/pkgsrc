# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:16 jlam Exp $

.if !defined(LWP_BUILDLINK2_MK)
LWP_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		lwp
BUILDLINK_DEPENDS.lwp?=		lwp>=1.6
BUILDLINK_PKGSRCDIR.lwp?=	../../devel/lwp

EVAL_PREFIX+=		BUILDLINK_PREFIX.lwp=lwp
BUILDLINK_PREFIX.lwp_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.lwp=	include/lwp/*
BUILDLINK_FILES.lwp+=	lib/liblwp.*

BUILDLINK_TARGETS+=	lwp-buildlink

lwp-buildlink: _BUILDLINK_USE

.endif	# LWP_BUILDLINK2_MK
