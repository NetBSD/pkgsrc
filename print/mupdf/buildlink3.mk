# $NetBSD: buildlink3.mk,v 1.8 2015/11/11 17:08:25 leot Exp $

BUILDLINK_TREE+=	mupdf

.if !defined(MUPDF_BUILDLINK3_MK)
MUPDF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mupdf+=	mupdf>=1.8
BUILDLINK_PKGSRCDIR.mupdf?=	../../print/mupdf

pkgbase := mupdf
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.mupdf:Mcurl)
.include "../../www/curl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif

.include "../../graphics/jbig2dec/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.endif	# MUPDF_BUILDLINK3_MK

BUILDLINK_TREE+=	-mupdf
