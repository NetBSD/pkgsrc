# $NetBSD: Makefile,v 1.1.1.1 2009/02/26 19:03:43 minskim Exp $

PKGNAME=	${DISTNAME:S/evas/evas-eet/}

COMMENT=	Evas EET image loader

EVAS_IMAGE_LOADERS=	eet

.include "../../graphics/evas/Makefile.common"

BUILD_DIRS=	src/modules/loaders/eet src/modules/savers/eet
MAKE_FLAGS+=	module_la_LIBADD="\$${EET_LIBS} ${BUILDLINK_PREFIX.evas}/lib/libevas.la"

.include "../../devel/eet/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
