# $NetBSD: buildlink2.mk,v 1.1 2002/09/10 06:10:04 jlam Exp $

.if !defined(DANTE_BUILDLINK2_MK)
DANTE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		dante
BUILDLINK_DEPENDS.dante?=	dante>=1.1.13
BUILDLINK_PKGSRCDIR.dante?=	../../net/dante

EVAL_PREFIX+=	BUILDLINK_PREFIX.dante=dante
BUILDLINK_PREFIX.dante_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.dante=	include/dante/*
BUILDLINK_FILES.dante+=	lib/libdsocks.*
BUILDLINK_FILES.dante+=	lib/libsocks.*

BUILDLINK_TARGETS+=	dante-buildlink

dante-buildlink: _BUILDLINK_USE

.endif	# DANTE_BUILDLINK2_MK
