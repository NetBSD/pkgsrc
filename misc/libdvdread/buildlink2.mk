# $NetBSD: buildlink2.mk,v 1.3 2003/02/26 10:12:34 wiz Exp $

.if !defined(LIBDVDREAD_BUILDLINK2_MK)
LIBDVDREAD_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libdvdread
BUILDLINK_DEPENDS.libdvdread?=		libdvdread>=0.9.4
BUILDLINK_PKGSRCDIR.libdvdread?=	../../misc/libdvdread

EVAL_PREFIX+=		BUILDLINK_PREFIX.libdvdread=libdvdread
BUILDLINK_PREFIX.libdvdread=	${LOCALBASE}
BUILDLINK_FILES.libdvdread=	include/dvdread/*
BUILDLINK_FILES.libdvdread+=	lib/libdvdread.*

BUILDLINK_TARGETS+=	libdvdread-buildlink

libdvdread-buildlink: _BUILDLINK_USE

.endif	# LIBDVDREAD_BUILDLINK2_MK
