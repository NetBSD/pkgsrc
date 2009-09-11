# $NetBSD: Makefile,v 1.4 2009/09/11 22:31:01 joerg Exp $

PKGNAME=	${DISTNAME:S/evas/evas-svg/}

COMMENT=	Evas SVG image loader

EVAS_IMAGE_LOADERS=	svg

.include "../../graphics/evas/Makefile.common"

BUILD_DIRS=	src/modules/loaders/svg
MAKE_FLAGS+=	module_la_LIBADD="\$${EINA_LIBS} \$${evas_image_loader_svg_libs} ${BUILDLINK_PREFIX.evas}/lib/libevas.la" \
		module_la_DEPENDENCIES=

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
