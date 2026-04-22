# $NetBSD: buildlink3.mk,v 1.1 2026/04/22 17:47:50 vins Exp $

BUILDLINK_TREE+=	avfs

.if !defined(AVFS_BUILDLINK3_MK)
AVFS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.avfs+=	avfs>=1.3.0
BUILDLINK_PKGSRCDIR.avfs?=	../../filesystems/avfs

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

pkgbase :=      avfs
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.avfs:Mfuse}
.  include "../../mk/fuse.buildlink3.mk"
.endif
.if ${PKG_BUILD_OPTIONS.avfs:Mzstd}
.  include "../../archivers/zstd/buildlink3.mk"
.endif
.if ${PKG_BUILD_OPTIONS.avfs:Mwebdav}
.  include "../../www/neon/buildlink3.mk"
.endif

.endif  # AVFS_BUILDLINK3_MK

BUILDLINK_TREE+=	-avfs
