# $NetBSD: buildlink2.mk,v 1.10 2003/09/03 16:38:37 jlam Exp $

.if !defined(LIBNBCOMPAT_BUILDLINK2_MK)
LIBNBCOMPAT_BUILDLINK2_MK=     # defined

BUILDLINK_DEPENDS.libnbcompat?=		libnbcompat>=20030827
BUILDLINK_PKGSRCDIR.libnbcompat?=	../../pkgtools/libnbcompat
BUILDLINK_DEPMETHOD.libnbcompat?=	build

BUILDLINK_PACKAGES+=		libnbcompat
EVAL_PREFIX+=			BUILDLINK_PREFIX.libnbcompat=libnbcompat
BUILDLINK_PREFIX.libnbcompat_DEFAULT=	${LOCALBASE}

BUILDLINK_FILES.libnbcompat=	include/libnbcompat/*/*
BUILDLINK_FILES.libnbcompat+=	include/libnbcompat/*
BUILDLINK_FILES.libnbcompat+=	lib/libnbcompat.*

BUILDLINK_CPPFLAGS.libnbcompat=	\
	-I${BUILDLINK_PREFIX.libnbcompat}/include/libnbcompat
BUILDLINK_LDADD.libnbcompat=	-lnbcompat

BUILDLINK_TARGETS+=	libnbcompat-buildlink

libnbcompat-buildlink: _BUILDLINK_USE

.if defined(GNU_CONFIGURE)
CPPFLAGS+=	${BUILDLINK_CPPFLAGS.libnbcompat}
CFLAGS+=	${BUILDLINK_CPPFLAGS.libnbcompat}
LIBS+=		${BUILDLINK_LDADD.libnbcompat}
.endif

.endif  # LIBNBCOMPAT_BUILDLINK2_MK
