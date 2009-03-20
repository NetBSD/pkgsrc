# $NetBSD: buildlink3.mk,v 1.4 2009/03/20 19:24:08 joerg Exp $

BUILDLINK_TREE+=	tokyocabinet

.if !defined(TOKYOCABINET_BUILDLINK3_MK)
TOKYOCABINET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tokyocabinet+=	tokyocabinet>=1.3.7
BUILDLINK_ABI_DEPENDS.tokyocabinet+=	tokyocabinet>=1.3.24
BUILDLINK_PKGSRCDIR.tokyocabinet?=	../../databases/tokyocabinet

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/lzmalib/buildlink3.mk"
.include "../../archivers/lzo/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # TOKYOCABINET_BUILDLINK3_MK

BUILDLINK_TREE+=	-tokyocabinet
