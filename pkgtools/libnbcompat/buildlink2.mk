# $NetBSD: buildlink2.mk,v 1.4 2003/06/10 06:35:27 grant Exp $
#

.if !defined(LIBNBCOMPAT_BUILDLINK2_MK)
LIBNBCOMPAT_BUILDLINK2_MK=     # defined

BUILDLINK_DEPMETHOD.libnbcompat=	build

.include "../../mk/bsd.prefs.mk"

BUILDLINK_DEPENDS.libnbcompat?=		libnbcompat>=20030331
BUILDLINK_PKGSRCDIR.libnbcompat?=	../../pkgtools/libnbcompat

BUILDLINK_PACKAGES+=		libnbcompat
EVAL_PREFIX+=			BUILDLINK_PREFIX.libnbcompat=libnbcompat
BUILDLINK_PREFIX.libnbcompat_DEFAULT=	${LOCALBASE}

BUILDLINK_FILES.libnbcompat+=	include/libnbcompat/*
BUILDLINK_FILES.libnbcompat+=	lib/libnbcompat.a

BUILDLINK_TARGETS+=	libnbcompat-buildlink

libnbcompat-buildlink: _BUILDLINK_USE

.endif  # LIBNBCOMPAT_BUILDLINK2_MK
