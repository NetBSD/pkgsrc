# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/03/31 05:02:18 grant Exp $
#

.if !defined(LIBPKGSRC_BUILDLINK2_MK)
LIBPKGSRC_BUILDLINK2_MK=     # defined

BUILDLINK_DEPMETHOD.libpkgsrc=	build

.include "../../mk/bsd.prefs.mk"

BUILDLINK_DEPENDS.libpkgsrc?=	libpkgsrc>=20030331
BUILDLINK_PKGSRCDIR.libpkgsrc?=	../../pkgtools/libpkgsrc

BUILDLINK_PACKAGES+=		libpkgsrc
EVAL_PREFIX+=			BUILDLINK_PREFIX.libpkgsrc=libpkgsrc
BUILDLINK_PREFIX.libpkgsrc_DEFAULT= ${LOCALBASE}

BUILDLINK_FILES.libpkgsrc+=	include/libpkgsrc/extern.h
BUILDLINK_FILES.libpkgsrc+=	include/libpkgsrc/ftpglob.h
BUILDLINK_FILES.libpkgsrc+=	include/libpkgsrc/fts.h
BUILDLINK_FILES.libpkgsrc+=	include/libpkgsrc/md5.h
BUILDLINK_FILES.libpkgsrc+=	include/libpkgsrc/mtree.h
BUILDLINK_FILES.libpkgsrc+=	include/libpkgsrc/namespace.h
BUILDLINK_FILES.libpkgsrc+=	include/libpkgsrc/nbcompat.h
BUILDLINK_FILES.libpkgsrc+=	include/libpkgsrc/nb-types.h
BUILDLINK_FILES.libpkgsrc+=	include/libpkgsrc/pack_dev.h
BUILDLINK_FILES.libpkgsrc+=	include/libpkgsrc/pwcache.h
BUILDLINK_FILES.libpkgsrc+=	include/libpkgsrc/rmd160.h
BUILDLINK_FILES.libpkgsrc+=	include/libpkgsrc/sha1.h
BUILDLINK_FILES.libpkgsrc+=	include/libpkgsrc/sha2.h
BUILDLINK_FILES.libpkgsrc+=	include/libpkgsrc/stat_flags.h
BUILDLINK_FILES.libpkgsrc+=	include/libpkgsrc/util.h
BUILDLINK_FILES.libpkgsrc+=	include/libpkgsrc/vis.h
BUILDLINK_FILES.libpkgsrc+=	lib/libpkgsrc.a

BUILDLINK_TARGETS+=	libpkgsrc-buildlink

libpkgsrc-buildlink: _BUILDLINK_USE

.endif  # LIBPKGSRC_BUILDLINK2_MK
