# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 19:21:53 jlam Exp $

.if !defined(LIBSIDPLAY_BUILDLINK2_MK)
LIBSIDPLAY_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libsidplay
BUILDLINK_DEPENDS.libsidplay?=		libsidplay>=1.36.38
BUILDLINK_PKGSRCDIR.libsidplay?=	../../audio/libsidplay

EVAL_PREFIX+=			BUILDLINK_PREFIX.libsidplay=libsidplay
BUILDLINK_PREFIX.libsidplay_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libsidplay=	include/sidplay/*
BUILDLINK_FILES.libsidplay+=	lib/libsidplay.*

BUILDLINK_TARGETS+=	libsidplay-buildlink

libsidplay-buildlink: _BUILDLINK_USE

.endif	# LIBSIDPLAY_BUILDLINK2_MK
