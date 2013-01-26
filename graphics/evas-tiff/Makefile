# $NetBSD: Makefile,v 1.10 2013/01/26 21:37:45 adam Exp $

PKGNAME=	evas-tiff-${EVAS_VERSION}

COMMENT=	Evas TIFF image loader

EVAS_IMAGE_LOADERS=	tiff

.include "../../graphics/evas/Makefile.common"

PKGREVISION=	2

BUILD_DIRS=	src/modules/loaders/tiff src/modules/savers/tiff
MAKE_FLAGS+=	module_la_LIBADD="\$${EINA_LIBS} \$${EVIL_LIBS} \$${evas_image_loader_tiff_libs} ${BUILDLINK_PREFIX.evas}/lib/libevas.la" \
		module_la_DEPENDENCIES=

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
