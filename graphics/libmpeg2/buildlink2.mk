# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/08/05 07:13:42 wulf Exp $
#
# This Makefile fragment is included by packages that use libmpeg2.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(LIBMPEG2_BUILDLINK2_MK)
LIBMPEG2_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libmpeg2
BUILDLINK_DEPENDS.libmpeg2?=		libmpeg2>=20030612
BUILDLINK_PKGSRCDIR.libmpeg2?=		../../graphics/libmpeg2

EVAL_PREFIX+=	BUILDLINK_PREFIX.libmpeg2=libmpeg2
BUILDLINK_PREFIX.libmpeg2_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libmpeg2+=	include/mpeg2dec/mpeg2.h
BUILDLINK_FILES.libmpeg2+=	include/mpeg2dec/convert.h
BUILDLINK_FILES.libmpeg2+=	lib/libmpeg2.*
BUILDLINK_FILES.libmpeg2+=	lib/pkgconfig/libmpeg2.pc

.include "../../devel/SDL/buildlink2.mk"

BUILDLINK_TARGETS+=	libmpeg2-buildlink

libmpeg2-buildlink: _BUILDLINK_USE

.endif	# LIBMPEG2_BUILDLINK2_MK
