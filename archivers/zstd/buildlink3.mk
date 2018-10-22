# $NetBSD: buildlink3.mk,v 1.2 2018/10/22 15:28:02 adam Exp $

BUILDLINK_TREE+=	zstd

.if !defined(ZSTD_BUILDLINK3_MK)
ZSTD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.zstd+=	zstd>=1.3.6
BUILDLINK_PKGSRCDIR.zstd?=	../../archivers/zstd
.endif	# ZSTD_BUILDLINK3_MK

BUILDLINK_TREE+=	-zstd
