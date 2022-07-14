# $NetBSD: Makefile,v 1.20 2022/07/14 23:46:21 dholland Exp $

PKGNAME=	evas-jpeg-${EVAS_VERSION}
PKGREVISION=	2
COMMENT=	Evas JPEG image loader

EVAS_IMAGE_LOADERS=	jpeg

.include "../../graphics/evas/Makefile.common"

BUILD_DIRS=	src/modules/loaders/jpeg src/modules/savers/jpeg
MAKE_FLAGS+=	module_la_LIBADD="\$${eavs_image_loader_jpeg_libs} \$${EINA_LIBS} ${BUILDLINK_PREFIX.evas}/lib/libevas.la" \
		module_la_DEPENDENCIES=

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
