# $NetBSD: Makefile,v 1.3 2025/02/04 11:22:48 wiz Exp $

.include "Makefile.common"
COMMENT=	JpegXL reference codec

TOOL_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DJPEGXL_VERSION=${PKGVERSION_NOREV}
CMAKE_CONFIGURE_ARGS+=	-DJPEGXL_FORCE_SYSTEM_BROTLI=ON
CMAKE_CONFIGURE_ARGS+=	-DJPEGXL_FORCE_SYSTEM_HWY=ON
CMAKE_CONFIGURE_ARGS+=	-DJPEGXL_FORCE_SYSTEM_LCMS2=ON
CMAKE_CONFIGURE_ARGS+=	-DJPEGXL_ENABLE_DOXYGEN=OFF
CMAKE_CONFIGURE_ARGS+=	-DJPEGXL_ENABLE_JPEGLI=OFF
CMAKE_CONFIGURE_ARGS+=	-DJPEGXL_ENABLE_SJPEG=OFF
CMAKE_CONFIGURE_ARGS+=	-DJPEGXL_ENABLE_SKCMS=OFF
CMAKE_CONFIGURE_ARGS+=	-DJPEGXL_ENABLE_PLUGINS=OFF
# test are run during the build stage
CMAKE_CONFIGURE_ARGS+=	-DBUILD_TESTING=OFF

REPLACE_BASH=	deps.sh

PKGCONFIG_OVERRIDE+=	lib/jxl/libjxl.pc.in
PKGCONFIG_OVERRIDE+=	lib/jxl/libjxl_cms.pc.in
PKGCONFIG_OVERRIDE+=	lib/threads/libjxl_threads.pc.in

.include "../../devel/cmake/build.mk"
.include "../../archivers/brotli/buildlink3.mk"
.include "../../graphics/libavif/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/libhighway/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
