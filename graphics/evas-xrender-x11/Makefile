# $NetBSD: Makefile,v 1.8 2011/11/01 06:01:32 sbd Exp $

PKGNAME=	${DISTNAME:S/evas/evas-xrender-x11/}
PKGREVISION=	3

COMMENT=	Evas Xrender X11 engine

EVAS_ENGINES=	xrender-x11

.include "../../graphics/evas/Makefile.common"

BUILD_DIRS=	src/modules/engines/xrender_x11
MAKE_FLAGS+=	module_la_LIBADD="\$${EINA_LIBS} ${BUILDLINK_PREFIX.evas}/lib/libevas.la \$${evas_engine_xrender_xcb_libs} \$${evas_engine_xrender_x11_libs}" \
		module_la_DEPENDENCIES=

INSTALLATION_DIRS+=	lib/pkgconfig
PKGCONFIG_OVERRIDE=	evas-xrender-x11.pc.in

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/evas-xrender-x11.pc \
		${DESTDIR}${PREFIX}/lib/pkgconfig

.include "../../mk/bsd.pkg.mk"
