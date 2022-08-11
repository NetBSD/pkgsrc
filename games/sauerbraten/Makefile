# $NetBSD: Makefile,v 1.9 2022/08/11 05:08:34 gutteridge Exp $

DISTNAME=	sauerbraten_2020_12_27_linux
PKGNAME=	sauerbraten-2020_12_27
PKGREVISION=	4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sauerbraten/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	http://sauerbraten.org/
COMMENT=	First-person shooter game based on Cube 2
LICENSE=	zlib AND cc-by-nc-sa-v3.0-license

USE_TOOLS+=	gmake pkg-config pax
USE_LANGUAGES=	c c++03

WRKSRC=		${WRKDIR}/sauerbraten
BUILD_DIRS+=	src
BUILD_TARGET=	client master server

# GCC precompiled headers...
RELRO_SUPPORTED=	no

LDFLAGS.NetBSD+=	-lrt
LDFLAGS.SunOS+=		-lsocket -lnsl

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	libexec
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/doc/sauerbraten
INSTALLATION_DIRS+=	share/sauerbraten/data
INSTALLATION_DIRS+=	share/sauerbraten/packages
INSTALLATION_DIRS+=	share/pixmaps

pre-configure:
.for prog in client master server
	${SED}	-e 's,@PREFIX@,${PREFIX},g' \
		< ${FILESDIR}/sauerbraten.sh.in > \
		${WRKDIR}/sauer_${prog}
.endfor

do-install:
.for prog in client master server
	${INSTALL_SCRIPT} ${WRKDIR}/sauer_${prog} \
	    ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/sauer_${prog} \
	    ${DESTDIR}${PREFIX}/libexec
.endfor
	${INSTALL_DATA} ${FILESDIR}/sauerbraten.desktop \
	    ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/data/cube.png \
	    ${DESTDIR}${PREFIX}/share/pixmaps/sauerbraten.png
	cd ${WRKSRC}/docs && ${PAX} -rw -pp . ${DESTDIR}${PREFIX}/share/doc/sauerbraten
	cd ${WRKSRC}/data && ${PAX} -rw -pp . ${DESTDIR}${PREFIX}/share/sauerbraten/data
	cd ${WRKSRC}/packages && ${PAX} -rw -pp . ${DESTDIR}${PREFIX}/share/sauerbraten/packages

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../net/enet/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
