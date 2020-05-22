# $NetBSD: buildlink3.mk,v 1.30 2020/05/22 17:44:41 nia Exp $

BUILDLINK_TREE+=	wine

.if !defined(WINE_BUILDLINK3_MK)
WINE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wine+=	wine>=1.3.0
BUILDLINK_ABI_DEPENDS.wine+=	wine>=1.6.2nb26
BUILDLINK_PKGSRCDIR.wine?=	../../emulators/wine
.endif # WINE_BUILDLINK3_MK

BUILDLINK_TREE+=	-wine
