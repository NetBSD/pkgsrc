# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/12/05 23:24:31 xtraeme Exp $
#
# This Makefile fragment is included by packages that use libgpg-error.
#
# This file was created automatically using createbuildlink 2.7.
#

.if !defined(LIBGPG_ERROR_BUILDLINK2_MK)
LIBGPG_ERROR_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libgpg-error
BUILDLINK_DEPENDS.libgpg-error?=		libgpg-error>=0.6
BUILDLINK_PKGSRCDIR.libgpg-error?=		../../security/libgpg-error

EVAL_PREFIX+=	BUILDLINK_PREFIX.libgpg-error=libgpg-error
BUILDLINK_PREFIX.libgpg-error_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libgpg-error+=	include/gpg-error.h
BUILDLINK_FILES.libgpg-error+=	lib/libgpg-error.*

BUILDLINK_TARGETS+=	libgpg-error-buildlink

libgpg-error-buildlink: _BUILDLINK_USE

.endif	# LIBGPG_ERROR_BUILDLINK2_MK
