# $NetBSD: Makefile,v 1.1.1.1 2009/02/26 19:06:55 minskim Exp $

PKGNAME=	${DISTNAME:S/evas/evas-jpeg/}

COMMENT=	Evas JPEG image loader

EVAS_IMAGE_LOADERS=	jpeg

.include "../../graphics/evas/Makefile.common"

BUILD_DIRS=	src/modules/loaders/jpeg src/modules/savers/jpeg
MAKE_FLAGS+=	module_la_LIBADD="\$${jpeg_libs} ${BUILDLINK_PREFIX.evas}/lib/libevas.la"

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
