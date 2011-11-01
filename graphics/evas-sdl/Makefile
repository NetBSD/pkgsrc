# $NetBSD: Makefile,v 1.8 2011/11/01 06:01:31 sbd Exp $

PKGNAME=	${DISTNAME:S/evas/evas-sdl/}
PKGREVISION=	3

COMMENT=	Evas SDL engine

EVAS_ENGINES=	sdl

.include "../../graphics/evas/Makefile.common"

CONFIGURE_ARGS+=	--enable-software-sdl

BUILD_DIRS=	src/modules/engines/software_sdl
MAKE_FLAGS+=	module_la_LIBADD="\$${EINA_LIBS} ${BUILDLINK_PREFIX.evas}/lib/libevas.la \$${evas_engine_software_sdl_libs}" \
		module_la_DEPENDENCIES=

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
