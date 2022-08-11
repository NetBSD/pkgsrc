# $NetBSD: Makefile,v 1.26 2022/08/11 05:08:18 gutteridge Exp $

DISTNAME=	free42-nologo-3.0.13
PKGNAME=	${DISTNAME:S/-nologo//}
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	https://thomasokken.com/free42/upstream/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://thomasokken.com/free42/
COMMENT=	HP42S Calculator Simulator
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake pkg-config pax
USE_LANGUAGES+=	c c++

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/doc/free42

do-configure:
	mkdir ${WRKSRC}/gtk-bcd
	cd ${WRKSRC}/gtk && ${PAX} -rw . ../gtk-bcd

do-build:
	cd ${WRKSRC}/gtk && ${BUILD_MAKE_CMD} free42bin
	cd ${WRKSRC}/gtk-bcd && ${BUILD_MAKE_CMD} BCD_MATH=1 free42dec

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gtk/free42bin \
		${DESTDIR}/${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/gtk-bcd/free42dec \
		${DESTDIR}/${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}/${PREFIX}/share/doc/free42/
	${INSTALL_DATA} ${WRKSRC}/gtk/README \
		${DESTDIR}/${PREFIX}/share/doc/free42/README.gtk
	${INSTALL_DATA} ${WRKSRC}/gtk/icon-128x128.xpm \
		${DESTDIR}/${PREFIX}/share/doc/free42/free42icon-128x128.xpm

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
MAKE_ENV+=	AUDIO_ALSA=1
.include "../../audio/alsa-lib/buildlink3.mk"
.endif
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
