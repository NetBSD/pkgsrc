# $NetBSD: buildlink2.mk,v 1.14 2003/09/16 16:49:51 grant Exp $

.if !defined(LIBNBCOMPAT_BUILDLINK2_MK)
LIBNBCOMPAT_BUILDLINK2_MK=     # defined

BUILDLINK_DEPENDS.libnbcompat?=		libnbcompat>=20030916
BUILDLINK_PKGSRCDIR.libnbcompat?=	../../pkgtools/libnbcompat
BUILDLINK_DEPMETHOD.libnbcompat?=	build

BUILDLINK_PACKAGES+=		libnbcompat
EVAL_PREFIX+=			BUILDLINK_PREFIX.libnbcompat=libnbcompat
BUILDLINK_PREFIX.libnbcompat_DEFAULT=	${LOCALBASE}

BUILDLINK_FILES.libnbcompat=	include/nbcompat.h
BUILDLINK_FILES.libnbcompat+=	include/nbcompat/*
BUILDLINK_FILES.libnbcompat+=	lib/libnbcompat.*

BUILDLINK_LDADD.libnbcompat=	-lnbcompat

BUILDLINK_TARGETS+=	libnbcompat-buildlink

libnbcompat-buildlink: _BUILDLINK_USE

.if defined(GNU_CONFIGURE)
LIBS+=		${BUILDLINK_LDADD.libnbcompat}
.endif

.endif  # LIBNBCOMPAT_BUILDLINK2_MK
