# $NetBSD: Makefile,v 1.9 2013/02/06 23:22:28 jperkin Exp $

PKGNAME=	evas-xpm-${EVAS_VERSION}
PKGREVISION=	1
COMMENT=	Evas XPM image loader

EVAS_IMAGE_LOADERS=	xpm

.include "../../graphics/evas/Makefile.common"

BUILD_DIRS=	src/modules/loaders/xpm
MAKE_FLAGS+=	module_la_LIBADD="\$${EINA_LIBS} \$${EVIL_LIBS} \$${evas_image_loader_xpm_libs} ${BUILDLINK_PREFIX.evas}/lib/libevas.la" \
		module_la_DEPENDENCIES=

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
