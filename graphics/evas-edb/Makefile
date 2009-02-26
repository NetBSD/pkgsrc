# $NetBSD: Makefile,v 1.1.1.1 2009/02/26 21:13:43 minskim Exp $

PKGNAME=	${DISTNAME:S/evas/evas-edb/}

COMMENT=	Evas Edb image loader

EVAS_IMAGE_LOADERS=	edb

.include "../../graphics/evas/Makefile.common"

BUILD_DIRS=	src/modules/loaders/edb src/modules/savers/edb
MAKE_FLAGS+=	module_la_LIBADD="\$${PNG_LIBS} ${BUILDLINK_PREFIX.evas}/lib/libevas.la"

.include "../../databases/edb/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
