# $NetBSD: buildlink3.mk,v 1.7 2010/01/17 02:45:00 obache Exp $

BUILDLINK_TREE+=	tokyocabinet

.if !defined(TOKYOCABINET_BUILDLINK3_MK)
TOKYOCABINET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tokyocabinet+=	tokyocabinet>=1.3.7
BUILDLINK_ABI_DEPENDS.tokyocabinet+=	tokyocabinet>=1.4.41
BUILDLINK_PKGSRCDIR.tokyocabinet?=	../../databases/tokyocabinet

pkgbase := tokyocabinet
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.tokyocabinet:Mbzip2)
.include "../../archivers/bzip2/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.tokyocabinet:Mlzma)
.include "../../archivers/lzmalib/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.tokyocabinet:Mlzo)
.include "../../archivers/lzo/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.tokyocabinet:Mzlib)
.include "../../devel/zlib/buildlink3.mk"
.endif

.include "../../mk/pthread.buildlink3.mk"
.endif # TOKYOCABINET_BUILDLINK3_MK

BUILDLINK_TREE+=	-tokyocabinet
