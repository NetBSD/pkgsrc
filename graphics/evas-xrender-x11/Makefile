# $NetBSD: Makefile,v 1.1.1.1 2009/02/26 19:33:49 minskim Exp $

PKGNAME=	${DISTNAME:S/evas/evas-xrender-x11/}

COMMENT=	Evas Xrender X11 engine

EVAS_ENGINES=	xrender-x11

.include "../../graphics/evas/Makefile.common"

BUILD_DIRS=	src/modules/engines/xrender_x11
MAKE_FLAGS+=	module_la_LIBADD="\$${x_libs} ${BUILDLINK_PREFIX.evas}/lib/libevas.la"

INSTALLATION_DIRS+=	lib/pkgconfig
PKGCONFIG_OVERRIDE=	evas-xrender-x11.pc.in

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/evas-xrender-x11.pc \
		${DESTDIR}${PREFIX}/lib/pkgconfig

.include "../../mk/bsd.pkg.mk"
