# $NetBSD: buildlink3.mk,v 1.4 2023/05/22 11:37:14 wiz Exp $

BUILDLINK_TREE+=	libimagequant

.if !defined(LIBIMAGEQUANT_BUILDLINK3_MK)
LIBIMAGEQUANT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libimagequant+=	libimagequant>=4.2.0
BUILDLINK_PKGSRCDIR.libimagequant?=	../../graphics/libimagequant
.endif	# LIBIMAGEQUANT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libimagequant
