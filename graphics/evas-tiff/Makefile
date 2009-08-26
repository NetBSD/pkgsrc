# $NetBSD: Makefile,v 1.3 2009/08/26 19:57:39 sno Exp $

PKGNAME=	${DISTNAME:S/evas/evas-tiff/}
PKGREVISION=	1

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
