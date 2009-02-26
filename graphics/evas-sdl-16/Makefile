# $NetBSD: Makefile,v 1.1.1.1 2009/02/26 21:00:11 minskim Exp $

PKGNAME=	${DISTNAME:S/evas/evas-sdl-16/}

COMMENT=	Evas 16-bit SDL engine

EVAS_ENGINES=	sdl

.include "../../graphics/evas/Makefile.common"

BUILD_DIRS=	src/modules/engines/software_16_sdl
MAKE_FLAGS+=	module_la_LIBADD="\$${x_libs} ${BUILDLINK_PREFIX.evas}/lib/libevas.la"

INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../devel/SDL/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
