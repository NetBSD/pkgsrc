# $NetBSD: buildlink2.mk,v 1.2 2003/05/13 03:07:10 salo Exp $
#

.if !defined(LIBGCRYPT_BUILDLINK2_MK)
LIBGCRYPT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libgcrypt
BUILDLINK_DEPENDS.libgcrypt?=		libgcrypt>=1.1.12
BUILDLINK_PKGSRCDIR.libgcrypt?=		../../security/libgcrypt

EVAL_PREFIX+=	BUILDLINK_PREFIX.libgcrypt=libgcrypt
BUILDLINK_PREFIX.libgcrypt_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libgcrypt+=	include/gcrypt.h
BUILDLINK_FILES.libgcrypt+=	lib/libgcrypt.*

BUILDLINK_TARGETS+=	libgcrypt-buildlink

libgcrypt-buildlink: _BUILDLINK_USE

.endif	# LIBGCRYPT_BUILDLINK2_MK
