# $NetBSD: buildlink2.mk,v 1.1.1.1 2004/01/25 00:14:56 kleink Exp $
#
# This Makefile fragment is included by packages that use libksba.
#
# This file was created automatically using createbuildlink-3.0.
#

.if !defined(LIBKSBA_BUILDLINK2_MK)
LIBKSBA_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libksba
BUILDLINK_DEPENDS.libksba?=		libksba>=0.9.1
BUILDLINK_PKGSRCDIR.libksba?=		../../security/libksba

EVAL_PREFIX+=	BUILDLINK_PREFIX.libksba=libksba
BUILDLINK_PREFIX.libksba_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libksba+=	include/ksba.h
BUILDLINK_FILES.libksba+=	lib/libksba.*

.include "../../security/libgcrypt/buildlink2.mk"
.include "../../security/libgpg-error/buildlink2.mk"

BUILDLINK_TARGETS+=	libksba-buildlink

libksba-buildlink: _BUILDLINK_USE

.endif	# LIBKSBA_BUILDLINK2_MK
