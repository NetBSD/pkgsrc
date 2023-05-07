# $NetBSD: buildlink3.mk,v 1.3 2023/05/07 16:55:20 wiz Exp $

BUILDLINK_TREE+=	libimagequant

.if !defined(LIBIMAGEQUANT_BUILDLINK3_MK)
LIBIMAGEQUANT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libimagequant+=	libimagequant>=2.8.2<4
BUILDLINK_PKGSRCDIR.libimagequant?=	../../graphics/libimagequant
.endif	# LIBIMAGEQUANT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libimagequant
