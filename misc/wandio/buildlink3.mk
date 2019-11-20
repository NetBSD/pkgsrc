# $NetBSD: buildlink3.mk,v 1.1 2019/11/20 20:52:41 adam Exp $

BUILDLINK_TREE+=	wandio

.if !defined(WANDIO_BUILDLINK3_MK)
WANDIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wandio+=	wandio>=4.2.2
BUILDLINK_PKGSRCDIR.wandio?=	../../misc/wandio

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/lz4/buildlink3.mk"
.include "../../archivers/lzo/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.endif	# WANDIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-wandio
