# $NetBSD: buildlink3.mk,v 1.17 2009/08/26 19:56:42 sno Exp $

BUILDLINK_TREE+=	poppler

.if !defined(POPPLER_BUILDLINK3_MK)
POPPLER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.poppler+=	poppler>=0.5.1
BUILDLINK_ABI_DEPENDS.poppler+=	poppler>=0.10.7nb2
BUILDLINK_PKGSRCDIR.poppler?=	../../print/poppler

pkgbase := poppler
.include "../../mk/pkg-build-options.mk"
.if !empty(PKG_BUILD_OPTIONS.poppler:Mpoppler-cms)
.include "../../graphics/lcms/buildlink3.mk"
.endif

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.endif # POPPLER_BUILDLINK3_MK

BUILDLINK_TREE+=	-poppler
