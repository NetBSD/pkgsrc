# $NetBSD: buildlink3.mk,v 1.2 2023/11/07 19:50:35 nros Exp $

BUILDLINK_TREE+=	minizip-ng

.if !defined(MINIZIP_NG_BUILDLINK3_MK)
MINIZIP_NG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.minizip-ng+=	minizip-ng>=4.0.2
BUILDLINK_PKGSRCDIR.minizip-ng?=	../../archivers/minizip-ng

.endif	# MINIZIP_NG_BUILDLINK3_MK

BUILDLINK_TREE+=	-minizip-ng
