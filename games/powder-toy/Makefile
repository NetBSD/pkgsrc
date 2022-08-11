# $NetBSD: Makefile,v 1.14 2022/08/11 05:08:34 gutteridge Exp $

DISTNAME=	powder-toy-95.0
PKGREVISION=	7
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
GCC_REQD+=	4.8

SCONS_ARGS+=	${_MAKE_JOBS}
SCONS_ARGS+=	--output=powder-toy

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

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SCONSBIN} ${SCONS_ARGS} \
	    CC=${CC:Q} CXX=${CXX:Q} CFLAGS=${CFLAGS:Q} CXXFLAGS=${CXXFLAGS:Q} \
	    LINKFLAGS=${LDFLAGS:Q} CPPPATH=${INCL_PATH:Q}
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
.include "../../devel/scons/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
