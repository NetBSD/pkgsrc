# $NetBSD: Makefile,v 1.1 2022/07/22 20:17:14 wiz Exp $

.include "../../graphics/libjxl/Makefile.common"
COMMENT=	JpegXL reference codec

TOOL_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

USE_TOOLS+=	bash pkg-config realpath
USE_LANGUAGES=	c c++
USE_CMAKE=	yes

CMAKE_ARGS+=	-DJPEGXL_VERSION=${PKGVERSION_NOREV}
CMAKE_ARGS+=	-DJPEGXL_FORCE_SYSTEM_BROTLI=ON
CMAKE_ARGS+=	-DJPEGXL_FORCE_SYSTEM_GTEST=ON
CMAKE_ARGS+=	-DJPEGXL_FORCE_SYSTEM_HWY=ON
CMAKE_ARGS+=	-DJPEGXL_ENABLE_SJPEG=OFF

REPLACE_BASH=	deps.sh

PKGCONFIG_OVERRIDE+=	lib/jxl/libjxl.pc.in
PKGCONFIG_OVERRIDE+=	lib/threads/libjxl_threads.pc.in

pre-configure:
	cd ${WRKSRC} && ./deps.sh

.include "../../archivers/brotli/buildlink3.mk"
.include "../../devel/googletest/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/libhighway/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
