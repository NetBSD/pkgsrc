# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/01/22 13:51:23 agc Exp $
#
# This Makefile fragment is included by packages that use libdvdcss.
#
# This file was created automatically using createbuildlink 2.3.
#

.if !defined(LIBDVDCSS_BUILDLINK2_MK)
LIBDVDCSS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libdvdcss
BUILDLINK_DEPENDS.libdvdcss?=		libdvdcss>=1.2.4
BUILDLINK_PKGSRCDIR.libdvdcss?=		../../misc/libdvdcss

EVAL_PREFIX+=	BUILDLINK_PREFIX.libdvdcss=libdvdcss
BUILDLINK_PREFIX.libdvdcss_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libdvdcss+=	include/dvdcss/dvdcss.h
BUILDLINK_FILES.libdvdcss+=	lib/libdvdcss.*

BUILDLINK_TARGETS+=	libdvdcss-buildlink

libdvdcss-buildlink: _BUILDLINK_USE

.endif	# LIBDVDCSS_BUILDLINK2_MK
