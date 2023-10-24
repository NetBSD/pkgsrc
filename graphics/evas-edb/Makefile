# $NetBSD: Makefile,v 1.20 2023/10/24 22:09:23 wiz Exp $

PKGNAME=	evas-edb-${EVAS_VERSION}
PKGREVISION=	3
COMMENT=	Evas Edb image loader

EVAS_IMAGE_LOADERS=	edb

.include "../../graphics/evas/Makefile.common"

BUILD_DIRS=	src/modules/loaders/edb src/modules/savers/edb
MAKE_FLAGS+=	module_la_LIBADD="\$${EDB_LIBS} \$${EINA_LIBS} ${BUILDLINK_PREFIX.evas}/lib/libevas.la" \
		module_la_DEPENDENCIES=

.include "../../databases/edb/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
