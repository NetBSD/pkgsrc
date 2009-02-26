# $NetBSD: Makefile,v 1.1.1.1 2009/02/26 20:43:13 minskim Exp $

PKGNAME=	${DISTNAME:S/evas/evas-sdl/}

COMMENT=	Evas SDL engine

EVAS_ENGINES=	sdl

.include "../../graphics/evas/Makefile.common"

BUILD_DIRS=	src/modules/engines/software_sdl
MAKE_FLAGS+=	module_la_LIBADD="\$${x_libs} ${BUILDLINK_PREFIX.evas}/lib/libevas.la"

INSTALLATION_DIRS+=	lib/pkgconfig
PKGCONFIG_OVERRIDE=	evas-software-sdl.pc.in

.include "../../devel/SDL/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/evas-software-sdl.pc \
		${DESTDIR}${PREFIX}/lib/pkgconfig

.include "../../mk/bsd.pkg.mk"
