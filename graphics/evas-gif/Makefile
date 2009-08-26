# $NetBSD: Makefile,v 1.3 2009/08/26 19:57:39 sno Exp $

PKGNAME=	${DISTNAME:S/evas/evas-gif/}
PKGREVISION=	1

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
