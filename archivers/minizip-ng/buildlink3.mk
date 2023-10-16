# $NetBSD: buildlink3.mk,v 1.1 2023/10/16 12:52:41 ryoon Exp $

BUILDLINK_TREE+=	minizip

.if !defined(MINIZIP_BUILDLINK3_MK)
MINIZIP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.minizip+=	minizip>=3.0.10
BUILDLINK_PKGSRCDIR.minizip?=	../../archivers/minizip-ng

.endif	# MINIZIP_BUILDLINK3_MK

BUILDLINK_TREE+=	-minizip
