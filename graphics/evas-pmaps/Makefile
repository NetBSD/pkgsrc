# $NetBSD: Makefile,v 1.1.1.1 2009/02/26 23:52:31 minskim Exp $

PKGNAME=	${DISTNAME:S/evas/evas-pmaps/}

COMMENT=	Evas PMAPS image loader

EVAS_IMAGE_LOADERS=	pmaps

.include "../../graphics/evas/Makefile.common"

BUILD_DIRS=	src/modules/loaders/pmaps
MAKE_FLAGS+=	module_la_LIBADD="\$${PNG_LIBS} ${BUILDLINK_PREFIX.evas}/lib/libevas.la"

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
