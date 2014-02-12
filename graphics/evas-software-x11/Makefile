# $NetBSD: Makefile,v 1.15 2014/02/12 23:18:00 tron Exp $

PKGNAME=	evas-software-x11-${EVAS_VERSION}
PKGREVISION=	1
COMMENT=	Evas software X11 engine

EVAS_ENGINES=	software-xlib

.include "../../graphics/evas/Makefile.common"

BUILD_DIRS=	src/modules/engines/software_x11
MAKE_FLAGS+=	module_la_LIBADD="\$${EINA_LIBS} \$${evas_engine_software_x11_libs} ${BUILDLINK_PREFIX.evas}/lib/libevas.la" \
		module_la_DEPENDENCIES=

INSTALLATION_DIRS+=	lib/pkgconfig
PKGCONFIG_OVERRIDE=	evas-software-x11.pc.in

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/evas-software-x11.pc \
		${DESTDIR}${PREFIX}/lib/pkgconfig

.include "../../mk/bsd.pkg.mk"
