# $NetBSD: buildlink2.mk,v 1.5 2003/08/31 20:22:09 jlam Exp $

.if !defined(LIBNBCOMPAT_BUILDLINK2_MK)
LIBNBCOMPAT_BUILDLINK2_MK=     # defined

BUILDLINK_DEPENDS.libnbcompat?=		libnbcompat>=20030331
BUILDLINK_PKGSRCDIR.libnbcompat?=	../../pkgtools/libnbcompat
BUILDLINK_DEPMETHOD.libnbcompat?=	build

BUILDLINK_PACKAGES+=		libnbcompat
EVAL_PREFIX+=			BUILDLINK_PREFIX.libnbcompat=libnbcompat
BUILDLINK_PREFIX.libnbcompat_DEFAULT=	${LOCALBASE}

BUILDLINK_FILES.libnbcompat+=	include/libnbcompat/*
BUILDLINK_FILES.libnbcompat+=	lib/libnbcompat.*

BUILDLINK_TARGETS+=	libnbcompat-buildlink

libnbcompat-buildlink: _BUILDLINK_USE

.endif  # LIBNBCOMPAT_BUILDLINK2_MK
