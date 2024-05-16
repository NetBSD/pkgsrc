# $NetBSD: Makefile,v 1.25 2024/05/16 06:14:56 wiz Exp $

DISTNAME=	powder-toy-95.0
PKGREVISION=	17
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=ThePowderToy/}
GITHUB_PROJECT=	The-Powder-Toy
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://powdertoy.co.uk/
COMMENT=	Desktop version of the 'falling sand' physics sandbox
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

USE_CXX_FEATURES+=	c++11

SCONS_BUILD_ARGS+=	${_MAKE_JOBS}
SCONS_BUILD_ARGS+=	--output=powder-toy
SCONS_DO_INSTALL=	no

CXXFLAGS+=	-DNO_INSTALL_CHECK

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	libexec
INSTALLATION_DIRS+=	share/appdata
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/doc/powder-toy
.for size in 16 24 32 48 128 256
INSTALLATION_DIRS+=	share/icons/hicolor/${size}x${size}/apps
.endfor

.include "options.mk"

post-build:
	${SED} -e 's,@PREFIX@,${PREFIX},g' < ${FILESDIR}/powder-toy.sh.in > \
	    ${WRKDIR}/powder-toy.sh

do-install:
	${INSTALL_DATA} ${WRKSRC}/README.md \
	    ${DESTDIR}${PREFIX}/share/doc/powder-toy
	${INSTALL_DATA} ${WRKSRC}/resources/powder.desktop \
	    ${DESTDIR}${PREFIX}/share/applications/powder-toy.desktop
	${INSTALL_DATA} ${WRKSRC}/resources/powder.appdata.xml \
	    ${DESTDIR}${PREFIX}/share/appdata/powder-toy.appdata.xml
	${INSTALL_SCRIPT} ${WRKDIR}/powder-toy.sh \
	    ${DESTDIR}${PREFIX}/bin/powder-toy
	${INSTALL_PROGRAM} ${WRKSRC}/build/powder-toy \
	    ${DESTDIR}${PREFIX}/libexec
.for size in 16 24 32 48 128 256
	${INSTALL_DATA} ${WRKSRC}/resources/icon/powder-${size}.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/${size}x${size}/apps/powder-toy.png
.endfor

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/scons4/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
