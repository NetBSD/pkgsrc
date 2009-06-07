# $NetBSD: Makefile,v 1.2 2009/06/07 21:12:12 joerg Exp $

PKGNAME=	${DISTNAME:S/evas/evas-software-16-x11/}

COMMENT=	Evas software 16-bit X11 engine

EVAS_ENGINES=	software-16-x11

.include "../../graphics/evas/Makefile.common"

BUILD_DIRS=	src/modules/engines/software_16_x11
MAKE_FLAGS+=	module_la_LIBADD="\$${EINA_LIBS} \$${evas_engine_software_16_x11_libs} ${BUILDLINK_PREFIX.evas}/lib/libevas.la" \
		module_la_DEPENDENCIES=

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
