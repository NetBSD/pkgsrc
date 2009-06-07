# $NetBSD: Makefile,v 1.2 2009/06/07 21:12:11 joerg Exp $

PKGNAME=	${DISTNAME:S/evas/evas-gif/}

COMMENT=	Evas GIF image loader

EVAS_IMAGE_LOADERS=	gif

.include "../../graphics/evas/Makefile.common"

BUILD_DIRS=	src/modules/loaders/gif
MAKE_FLAGS+=	module_la_LIBADD="\$${evas_image_loader_gif_libs} \$${EINA_LIBS} ${BUILDLINK_PREFIX.evas}/lib/libevas.la" \
		module_la_DEPENDENCIES=

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
