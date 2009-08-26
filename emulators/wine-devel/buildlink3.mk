# $NetBSD: buildlink3.mk,v 1.3 2009/08/26 19:56:42 sno Exp $

BUILDLINK_TREE+=	wine

.if !defined(WINE_BUILDLINK3_MK)
WINE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wine+=	wine>=0.9.6nb1
BUILDLINK_ABI_DEPENDS.wine?=	wine>=1.1.16
BUILDLINK_PKGSRCDIR.wine?=	../../emulators/wine

pkgbase:= wine
.include "../../mk/pkg-build-options.mk"

.include "../../graphics/freetype2/buildlink3.mk"
.if !empty(PKG_BUILD_OPTIONS.wine:Mopengl)
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.endif
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.endif # WINE_BUILDLINK3_MK

BUILDLINK_TREE+=	-wine
