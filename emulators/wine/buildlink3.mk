# $NetBSD: buildlink3.mk,v 1.26 2014/05/31 15:56:26 wiz Exp $

BUILDLINK_TREE+=	wine

.if !defined(WINE_BUILDLINK3_MK)
WINE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wine+=	wine>=1.3.0
BUILDLINK_ABI_DEPENDS.wine+=	wine>=1.6.2nb2
BUILDLINK_PKGSRCDIR.wine?=	../../emulators/wine

pkgbase:= wine
.include "../../mk/pkg-build-options.mk"

.include "../../graphics/freetype2/buildlink3.mk"
.if !empty(PKG_BUILD_OPTIONS.wine:Mopengl)
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.endif
.include "../../graphics/giflib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.endif # WINE_BUILDLINK3_MK

BUILDLINK_TREE+=	-wine
