# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/02/02 17:27:48 tron Exp $

.if !defined(LIBGCRYPT_BUILDLINK2_MK)
LIBGCRYPT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libgcrypt
BUILDLINK_DEPENDS.libgcrypt?=		libgcrypt>=1.1.11
BUILDLINK_PKGSRCDIR.libgcrypt?=		../../security/libgcrypt

EVAL_PREFIX+=	BUILDLINK_PREFIX.libgcrypt=libgcrypt
BUILDLINK_PREFIX.libgcrypt_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libgcrypt+=	include/gcrypt.h
BUILDLINK_FILES.libgcrypt+=	lib/libgcrypt.*

BUILDLINK_TARGETS+=	libgcrypt-buildlink

libgcrypt-buildlink: _BUILDLINK_USE

.endif	# LIBGCRYPT_BUILDLINK2_MK
