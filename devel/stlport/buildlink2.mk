# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:20 jlam Exp $

.if !defined(STLPORT_BUILDLINK2_MK)
STLPORT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		stlport
BUILDLINK_DEPENDS.stlport?=	stlport>=4.0
BUILDLINK_PKGSRCDIR.stlport?=	../../devel/stlport

EVAL_PREFIX+=			BUILDLINK_PREFIX.stlport=stlport
BUILDLINK_PREFIX.stlport_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.stlport=	include/stlport/*
BUILDLINK_FILES.stlport+=	include/stlport/*/*
BUILDLINK_FILES.stlport+=	lib/libstlport*

BUILDLINK_TARGETS+=	stlport-buildlink

stlport-buildlink: _BUILDLINK_USE

.endif	# STLPORT_BUILDLINK2_MK
