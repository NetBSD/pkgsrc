# $NetBSD: Makefile,v 1.25 2023/11/12 13:21:56 wiz Exp $

PKGNAME=	evas-tiff-${EVAS_VERSION}
PKGREVISION=	6

COMMENT=	Evas TIFF image loader

EVAS_IMAGE_LOADERS=	tiff

.include "../../graphics/evas/Makefile.common"

BUILD_DIRS=	src/modules/loaders/tiff src/modules/savers/tiff
MAKE_FLAGS+=	module_la_LIBADD="\$${EINA_LIBS} \$${EVIL_LIBS} \$${evas_image_loader_tiff_libs} ${BUILDLINK_PREFIX.evas}/lib/libevas.la" \
		module_la_DEPENDENCIES=

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
