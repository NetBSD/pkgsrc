# $NetBSD: buildlink2.mk,v 1.4 2002/09/30 23:41:31 jlam Exp $

.if !defined(STLPORT_BUILDLINK2_MK)
STLPORT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		stlport
BUILDLINK_DEPENDS.stlport?=	stlport>=4.0nb1
BUILDLINK_PKGSRCDIR.stlport?=	../../devel/stlport
BUILDLINK_DEPMETHOD.stlport?=	build

EVAL_PREFIX+=			BUILDLINK_PREFIX.stlport=stlport
BUILDLINK_PREFIX.stlport_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.stlport=	include/stlport/*
BUILDLINK_FILES.stlport+=	include/stlport/*/*
BUILDLINK_FILES.stlport+=	lib/libstlport*

BUILDLINK_TARGETS+=	stlport-buildlink

stlport-buildlink: _BUILDLINK_USE

.endif	# STLPORT_BUILDLINK2_MK
