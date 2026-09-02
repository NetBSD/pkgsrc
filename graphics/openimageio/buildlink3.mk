# $NetBSD: buildlink3.mk,v 1.87 2026/09/02 11:12:22 adam Exp $

BUILDLINK_TREE+=	openimageio

.if !defined(OPENIMAGEIO_BUILDLINK3_MK)
OPENIMAGEIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openimageio+=	openimageio>=2.4.12.0
BUILDLINK_ABI_DEPENDS.openimageio+=	openimageio>=3.1.14.1nb3
BUILDLINK_PKGSRCDIR.openimageio?=	../../graphics/openimageio

# these are targets in the cmake config files
BUILDLINK_FILES.openimageio+=		bin/iconvert
BUILDLINK_FILES.openimageio+=		bin/idiff
BUILDLINK_FILES.openimageio+=		bin/igrep
BUILDLINK_FILES.openimageio+=		bin/iinfo
BUILDLINK_FILES.openimageio+=		bin/maketx
BUILDLINK_FILES.openimageio+=		bin/oiiotool
BUILDLINK_FILES.openimageio+=		bin/testtex

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../textproc/fmtlib/buildlink3.mk"
.endif	# OPENIMAGEIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-openimageio
