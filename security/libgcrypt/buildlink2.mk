# $NetBSD: buildlink2.mk,v 1.4 2003/12/06 00:26:59 xtraeme Exp $
#
# This Makefile fragment is included by packages that use libgcrypt.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(LIBGCRYPT_BUILDLINK2_MK)
LIBGCRYPT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libgcrypt
BUILDLINK_DEPENDS.libgcrypt?=		libgcrypt>=1.1.90
BUILDLINK_PKGSRCDIR.libgcrypt?=		../../security/libgcrypt

EVAL_PREFIX+=	BUILDLINK_PREFIX.libgcrypt=libgcrypt
BUILDLINK_PREFIX.libgcrypt_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libgcrypt+=	include/gcrypt-module.h
BUILDLINK_FILES.libgcrypt+=	include/gcrypt.h
BUILDLINK_FILES.libgcrypt+=	lib/libgcrypt*

.include "../../security/libgpg-error/buildlink2.mk"

BUILDLINK_TARGETS+=	libgcrypt-buildlink

libgcrypt-buildlink: _BUILDLINK_USE

.endif	# LIBGCRYPT_BUILDLINK2_MK
