# $NetBSD: buildlink2.mk,v 1.1.1.1 2004/01/28 14:30:24 recht Exp $

.if !defined(LIBDVDPLAY_BUILDLINK2_MK)
LIBDVDPLAY_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libdvdplay
BUILDLINK_DEPENDS.libdvdplay?=		libdvdplay>=1.0.1
BUILDLINK_PKGSRCDIR.libdvdplay?=	../../multimedia/libdvdplay

EVAL_PREFIX+=		BUILDLINK_PREFIX.libdvdplay=libdvdplay
BUILDLINK_PREFIX.libdvdplay=	${LOCALBASE}
BUILDLINK_FILES.libdvdplay=	include/dvdplay/*
BUILDLINK_FILES.libdvdplay+=	lib/libdvdplay.*

BUILDLINK_TARGETS+=	libdvdplay-buildlink

libdvdplay-buildlink: _BUILDLINK_USE

.endif	# LIBDVDPLAY_BUILDLINK2_MK
