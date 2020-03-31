# $NetBSD: buildlink3.mk,v 1.1 2020/03/31 10:25:28 nia Exp $

BUILDLINK_TREE+=	minizip

.if !defined(MINIZIP_BUILDLINK3_MK)
MINIZIP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.minizip+=	minizip>=1.2.11
BUILDLINK_PKGSRCDIR.minizip?=	../../archivers/minizip

.include "../../devel/zlib/buildlink3.mk"
.endif	# MINIZIP_BUILDLINK3_MK

BUILDLINK_TREE+=	-minizip
