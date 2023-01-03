# $NetBSD: buildlink3.mk,v 1.46 2023/01/03 15:48:38 wiz Exp $

BUILDLINK_TREE+=	mupdf

.if !defined(MUPDF_BUILDLINK3_MK)
MUPDF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mupdf+=	mupdf>=1.14.0
BUILDLINK_ABI_DEPENDS.mupdf?=	mupdf>=1.20.3nb1
BUILDLINK_PKGSRCDIR.mupdf?=	../../print/mupdf

pkgbase := mupdf
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.mupdf:Mcurl}
.include "../../www/curl/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.mupdf:Mopengl}
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freeglut/buildlink3.mk"
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jbig2dec/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../www/gumbo-parser/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif	# MUPDF_BUILDLINK3_MK

BUILDLINK_TREE+=	-mupdf
