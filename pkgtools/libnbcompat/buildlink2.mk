# $NetBSD: buildlink2.mk,v 1.3 2003/03/31 05:56:35 grant Exp $
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

BUILDLINK_FILES.libnbcompat+=	include/libnbcompat/extern.h
BUILDLINK_FILES.libnbcompat+=	include/libnbcompat/ftpglob.h
BUILDLINK_FILES.libnbcompat+=	include/libnbcompat/fts.h
BUILDLINK_FILES.libnbcompat+=	include/libnbcompat/md5.h
BUILDLINK_FILES.libnbcompat+=	include/libnbcompat/mtree.h
BUILDLINK_FILES.libnbcompat+=	include/libnbcompat/namespace.h
BUILDLINK_FILES.libnbcompat+=	include/libnbcompat/nbcompat.h
BUILDLINK_FILES.libnbcompat+=	include/libnbcompat/nbtypes.h
BUILDLINK_FILES.libnbcompat+=	include/libnbcompat/pack_dev.h
BUILDLINK_FILES.libnbcompat+=	include/libnbcompat/pwcache.h
BUILDLINK_FILES.libnbcompat+=	include/libnbcompat/rmd160.h
BUILDLINK_FILES.libnbcompat+=	include/libnbcompat/sha1.h
BUILDLINK_FILES.libnbcompat+=	include/libnbcompat/sha2.h
BUILDLINK_FILES.libnbcompat+=	include/libnbcompat/stat_flags.h
BUILDLINK_FILES.libnbcompat+=	include/libnbcompat/util.h
BUILDLINK_FILES.libnbcompat+=	include/libnbcompat/vis.h
BUILDLINK_FILES.libnbcompat+=	lib/libnbcompat.a

BUILDLINK_TARGETS+=	libnbcompat-buildlink

libnbcompat-buildlink: _BUILDLINK_USE

.endif  # LIBNBCOMPAT_BUILDLINK2_MK
