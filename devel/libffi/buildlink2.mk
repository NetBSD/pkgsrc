# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/07/18 12:39:40 agc Exp $
#
# This Makefile fragment is included by packages that use libffi.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(LIBFFI_BUILDLINK2_MK)
LIBFFI_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libffi
BUILDLINK_DEPENDS.libffi?=		libffi>=1.20
BUILDLINK_PKGSRCDIR.libffi?=		../../devel/libffi

EVAL_PREFIX+=	BUILDLINK_PREFIX.libffi=libffi
BUILDLINK_PREFIX.libffi_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libffi+=	include/ffi.h
BUILDLINK_FILES.libffi+=	include/ffi_mips.h
BUILDLINK_FILES.libffi+=	include/fficonfig.h
BUILDLINK_FILES.libffi+=	lib/libffi-2.00-beta.*
BUILDLINK_FILES.libffi+=	lib/libffi.*

BUILDLINK_TARGETS+=	libffi-buildlink

libffi-buildlink: _BUILDLINK_USE

.endif	# LIBFFI_BUILDLINK2_MK
