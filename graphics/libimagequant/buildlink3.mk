# $NetBSD: buildlink3.mk,v 1.1 2017/01/29 11:57:03 adam Exp $

BUILDLINK_TREE+=	libimagequant

.if !defined(LIBIMAGEQUANT_BUILDLINK3_MK)
LIBIMAGEQUANT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libimagequant+=	libimagequant>=2.8.2
BUILDLINK_PKGSRCDIR.libimagequant?=	../../graphics/libimagequant
.endif	# LIBIMAGEQUANT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libimagequant
