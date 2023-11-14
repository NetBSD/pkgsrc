# $NetBSD: buildlink3.mk,v 1.2 2023/11/14 16:16:56 nia Exp $

BUILDLINK_TREE+=	minizip

.if !defined(MINIZIP_BUILDLINK3_MK)
MINIZIP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.minizip+=	minizip>=1.2.11
BUILDLINK_PKGSRCDIR.minizip?=	../../archivers/minizip
BUILDLINK_INCDIRS.minizip+=	include/minizip

.include "../../devel/zlib/buildlink3.mk"
.endif	# MINIZIP_BUILDLINK3_MK

BUILDLINK_TREE+=	-minizip
