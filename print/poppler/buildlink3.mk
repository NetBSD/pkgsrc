# $NetBSD: buildlink3.mk,v 1.121 2026/08/24 08:42:29 adam Exp $

BUILDLINK_TREE+=	poppler

.if !defined(POPPLER_BUILDLINK3_MK)
POPPLER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.poppler+=	poppler>=0.5.1
BUILDLINK_ABI_DEPENDS.poppler+=	poppler>=26.06.0nb2
BUILDLINK_PKGSRCDIR.poppler?=	../../print/poppler

USE_CXX_FEATURES+=	c++20

.include "../../devel/nss/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
BUILDLINK_API_DEPENDS.fontconfig+=	fontconfig>=2.15
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../security/gpgmepp/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.endif # POPPLER_BUILDLINK3_MK

BUILDLINK_TREE+=	-poppler
