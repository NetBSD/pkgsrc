# $NetBSD: buildlink2.mk,v 1.1 2003/01/09 11:21:40 uebayasi Exp $
#
# This Makefile fragment is included by packages that use libcomprex.
#
# This file was created automatically using createbuildlink 2.4.
#

.if !defined(LIBCOMPREX_BUILDLINK2_MK)
LIBCOMPREX_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libcomprex
BUILDLINK_DEPENDS.libcomprex?=		libcomprex>=0.3.2
BUILDLINK_PKGSRCDIR.libcomprex?=		../../archivers/libcomprex

EVAL_PREFIX+=	BUILDLINK_PREFIX.libcomprex=libcomprex
BUILDLINK_PREFIX.libcomprex_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libcomprex+=	include/comprex.h
BUILDLINK_FILES.libcomprex+=	include/libcomprex/*
BUILDLINK_FILES.libcomprex+=	lib/comprex/archive/*
BUILDLINK_FILES.libcomprex+=	lib/comprex/scheme/*
BUILDLINK_FILES.libcomprex+=	lib/libcomprex.*

.include "../../www/curl/buildlink2.mk"

BUILDLINK_TARGETS+=	libcomprex-buildlink

libcomprex-buildlink: _BUILDLINK_USE

.endif	# LIBCOMPREX_BUILDLINK2_MK
