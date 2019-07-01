# $NetBSD: Makefile,v 1.2 2019/07/01 04:08:09 ryoon Exp $

PKGNAME=	assaultcube-1.2.0.2
PKGREVISION=	1
DISTNAME=	AssaultCube_v${PKGVERSION_NOREV}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=assaultcube/}
EXTRACT_SUFX=	.tar.bz2
GITHUB_PROJECT=	AC
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://assault.cubers.net/
COMMENT=	Cube-based FPS with realistic environments
LICENSE=	zlib AND x11 AND cc-by-nc-nd-v2.5-license

BUILD_DIRS=	source/src
BUILD_TARGET=	client master server
USE_TOOLS+=	gmake pax pkg-config
USE_LANGUAGES=	c c++

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	libexec
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/assaultcube/config
INSTALLATION_DIRS+=	share/assaultcube/packages
INSTALLATION_DIRS+=	share/assaultcube/scripts
INSTALLATION_DIRS+=	share/icons/hicolor/256x256/apps

pre-configure:
	${RM} -f ${WRKSRC}/source/include/libintl.h
.for prog in client master server
	${SED}  -e 's,@PREFIX@,${PREFIX},g' \
                < ${FILESDIR}/assaultcube.sh.in > \
                ${WRKDIR}/ac_${prog}
.endfor

do-install:
.for prog in client master server
	${INSTALL_SCRIPT} ${WRKDIR}/ac_${prog} \
            ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/source/src/ac_${prog} \
	    ${DESTDIR}${PREFIX}/libexec
.endfor
.for f in config packages scripts
	cd ${WRKSRC}/${f} && ${PAX} -rw -pp . ${DESTDIR}${PREFIX}/share/assaultcube/${f}
.endfor
	${INSTALL_DATA} ${WRKSRC}/docs/images/icon.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/256x256/apps/assaultcube.png
	${INSTALL_DATA} ${FILESDIR}/assaultcube.desktop \
	    ${DESTDIR}${PREFIX}/share/applications

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../net/enet/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
