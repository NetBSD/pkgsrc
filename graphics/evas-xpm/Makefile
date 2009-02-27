# $NetBSD: Makefile,v 1.1.1.1 2009/02/27 04:20:48 minskim Exp $

PKGNAME=	${DISTNAME:S/evas/evas-xpm/}

COMMENT=	Evas XPM image loader

EVAS_IMAGE_LOADERS=	xpm

.include "../../graphics/evas/Makefile.common"

BUILD_DIRS=	src/modules/loaders/xpm
MAKE_FLAGS+=	module_la_LIBADD="\$${PNG_LIBS} ${BUILDLINK_PREFIX.evas}/lib/libevas.la"

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
