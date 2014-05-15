# $NetBSD: Makefile,v 1.16 2014/05/15 14:41:51 adam Exp $

PKGNAME=	evas-gif-${EVAS_VERSION}
PKGREVISION=	3
COMMENT=	Evas GIF image loader

EVAS_IMAGE_LOADERS=	gif

.include "../../graphics/evas/Makefile.common"

BUILD_DIRS=	src/modules/loaders/gif
MAKE_FLAGS+=	module_la_LIBADD="\$${evas_image_loader_gif_libs} \$${EINA_LIBS} ${BUILDLINK_PREFIX.evas}/lib/libevas.la" \
		module_la_DEPENDENCIES=

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/giflib.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
