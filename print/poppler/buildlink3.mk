# $NetBSD: buildlink3.mk,v 1.27 2012/07/04 20:25:16 drochner Exp $

BUILDLINK_TREE+=	poppler

.if !defined(POPPLER_BUILDLINK3_MK)
POPPLER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.poppler+=	poppler>=0.5.1
BUILDLINK_ABI_DEPENDS.poppler+=	poppler>=0.20.1
BUILDLINK_PKGSRCDIR.poppler?=	../../print/poppler

pkgbase := poppler
.include "../../mk/pkg-build-options.mk"
.if !empty(PKG_BUILD_OPTIONS.poppler:Mpoppler-cms)
.include "../../graphics/lcms/buildlink3.mk"
.endif

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.endif # POPPLER_BUILDLINK3_MK

BUILDLINK_TREE+=	-poppler
