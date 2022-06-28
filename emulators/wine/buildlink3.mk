# $NetBSD: buildlink3.mk,v 1.31 2022/06/28 11:33:51 wiz Exp $

BUILDLINK_TREE+=	wine

.if !defined(WINE_BUILDLINK3_MK)
WINE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wine+=	wine>=1.3.0
BUILDLINK_ABI_DEPENDS.wine+=	wine>=5.0.5nb9
BUILDLINK_PKGSRCDIR.wine?=	../../emulators/wine
.endif # WINE_BUILDLINK3_MK

BUILDLINK_TREE+=	-wine
