# $NetBSD: buildlink2.mk,v 1.2 2004/02/10 05:31:48 minskim Exp $
#
# This Makefile fragment is included by packages that use libgpg-error.
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

.include "../../devel/gettext-lib/buildlink2.mk"

BUILDLINK_TARGETS+=	libgpg-error-buildlink

libgpg-error-buildlink: _BUILDLINK_USE

.endif	# LIBGPG_ERROR_BUILDLINK2_MK
