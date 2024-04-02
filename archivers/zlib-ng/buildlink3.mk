# $NetBSD: buildlink3.mk,v 1.1 2024/04/02 20:15:01 adam Exp $

BUILDLINK_TREE+=	zlib-ng

.if !defined(ZLIB_NG_BUILDLINK3_MK)
ZLIB_NG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.zlib-ng+=	zlib-ng>=2.1.6
BUILDLINK_PKGSRCDIR.zlib-ng?=	../../archivers/zlib-ng
.endif	# ZLIB_NG_BUILDLINK3_MK

BUILDLINK_TREE+=	-zlib-ng
