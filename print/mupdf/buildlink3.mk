# $NetBSD: buildlink3.mk,v 1.5 2014/05/15 14:41:58 adam Exp $

BUILDLINK_TREE+=	mupdf

.if !defined(MUPDF_BUILDLINK3_MK)
MUPDF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mupdf+=	mupdf>=1.3
BUILDLINK_ABI_DEPENDS.mupdf?=	mupdf>=1.4nb1
BUILDLINK_PKGSRCDIR.mupdf?=	../../print/mupdf

.include "../../graphics/jbig2dec/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.endif	# MUPDF_BUILDLINK3_MK

BUILDLINK_TREE+=	-mupdf
