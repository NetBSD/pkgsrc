# $NetBSD: buildlink3.mk,v 1.1 2023/05/22 11:24:13 adam Exp $

BUILDLINK_TREE+=	blosc2

.if !defined(BLOSC2_BUILDLINK3_MK)
BLOSC2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.blosc2+=	blosc2>=2.9.2
BUILDLINK_PKGSRCDIR.blosc2?=	../../devel/blosc2

.include "../../archivers/lz4/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif	# BLOSC2_BUILDLINK3_MK

BUILDLINK_TREE+=	-blosc2
