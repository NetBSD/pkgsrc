# $NetBSD: Makefile,v 1.24 2023/11/12 13:21:56 wiz Exp $

PKGNAME=	evas-png-${EVAS_VERSION}
PKGREVISION=	4
COMMENT=	Evas PNG image loader

EVAS_IMAGE_LOADERS=	png

.include "../../graphics/evas/Makefile.common"

BUILD_DIRS=	src/modules/loaders/png src/modules/savers/png
MAKE_FLAGS+=	module_la_LIBADD="\$${PNG_LIBS} \$${EINA_LIBS} ${BUILDLINK_PREFIX.evas}/lib/libevas.la" \
		module_la_DEPENDENCIES=

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
