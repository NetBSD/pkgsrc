# $NetBSD: Makefile,v 1.1.1.1 2009/02/26 19:26:52 minskim Exp $

PKGNAME=	${DISTNAME:S/evas/evas-software-16-x11/}

COMMENT=	Evas software 16-bit X11 engine

EVAS_ENGINES=	software-16-x11

.include "../../graphics/evas/Makefile.common"

BUILD_DIRS=	src/modules/engines/software_16_x11
MAKE_FLAGS+=	module_la_LIBADD="\$${x_libs} ${BUILDLINK_PREFIX.evas}/lib/libevas.la"

INSTALLATION_DIRS+=	lib/pkgconfig
PKGCONFIG_OVERRIDE=	evas-software-16-x11.pc.in

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/evas-software-16-x11.pc \
		${DESTDIR}${PREFIX}/lib/pkgconfig

.include "../../mk/bsd.pkg.mk"
