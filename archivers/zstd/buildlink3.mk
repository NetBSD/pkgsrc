# $NetBSD: buildlink3.mk,v 1.1 2017/03/08 16:51:36 wiz Exp $

BUILDLINK_TREE+=	zstd

.if !defined(ZSTD_BUILDLINK3_MK)
ZSTD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.zstd+=	zstd>=1.1.3
BUILDLINK_PKGSRCDIR.zstd?=	../../archivers/zstd
.endif	# ZSTD_BUILDLINK3_MK

BUILDLINK_TREE+=	-zstd
