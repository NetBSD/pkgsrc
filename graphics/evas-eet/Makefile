# $NetBSD: Makefile,v 1.22 2025/04/24 14:14:16 wiz Exp $

PKGNAME=	evas-eet-${EVAS_VERSION}
PKGREVISION=	5
COMMENT=	Evas EET image loader

EVAS_IMAGE_LOADERS=	eet

.include "../../graphics/evas/Makefile.common"

BUILD_DIRS=	src/modules/loaders/eet src/modules/savers/eet
MAKE_FLAGS+=	module_la_LIBADD="\$${EET_LIBS} \$${EINA_LIBS} ${BUILDLINK_PREFIX.evas}/lib/libevas.la" \
		module_la_DEPENDENCIES=

.include "../../devel/eet/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
