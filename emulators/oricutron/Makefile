# $NetBSD: Makefile,v 1.1 2026/02/14 14:17:10 nia Exp $

ORICUTRON_VER=	1.2.14

PKGNAME=	oricutron-${ORICUTRON_VER}
CATEGORIES=	emulators

DIST_SUBDIR=	${PKGNAME_NOREV}
DISTFILES+=	Oricutron_win32_v12.zip
DISTFILES+=	V${ORICUTRON_VER:S/./_/g}.tar.gz

SITES.V${ORICUTRON_VER:S/./_/g}.tar.gz= \
	https://github.com/pete-gordon/oricutron/archive/refs/tags/

SITES.Oricutron_win32_v12.zip= \
	https://web.archive.org/web/20210707230951/http://www.petergordon.org.uk/oricutron/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pete-gordon/oricutron
COMMENT=	Portable Oric 8-bit computer emulator
LICENSE=	gnu-gpl-v2

# not actually written in C++ but cmake still checks...
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config pax

WRKSRC=		${WRKDIR}/${PKGBASE}-${ORICUTRON_VER:S/./_/g}

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	system.h
SUBST_VARS.paths=	PREFIX

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/doc/${PKGBASE}
.for i in 16 32 64 128 256
INSTALLATION_DIRS+=	share/icons/hicolor/${i}x${i}/apps
.endfor
INSTALLATION_DIRS+=	share/${PKGBASE}/images
INSTALLATION_DIRS+=	share/${PKGBASE}/roms

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${CMAKE_BUILD_DIR}/Oricutron \
	    ${DESTDIR}${PREFIX}/bin/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/${PKGBASE}.desktop \
	    ${DESTDIR}${PREFIX}/share/applications/${PKGBASE}.desktop
	${INSTALL_DATA} ${WRKSRC}/images/* \
	    ${DESTDIR}${PREFIX}/share/${PKGBASE}/images
	${INSTALL_DATA} ${WRKDIR}/roms/* \
	    ${DESTDIR}${PREFIX}/share/${PKGBASE}/roms
.for i in ReadMe.txt ReadMe-LiesMich_DE.txt
	${INSTALL_DATA} ${WRKSRC}/${i} \
	    ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/
.endfor
.for i in 16 32 64
	${INSTALL_DATA} ${WRKSRC}/XCode/Oricutron/Oricutron/Images.xcassets/AppIcon.appiconset/winicon${i}.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps/${PKGBASE}.png
.endfor
.for i in 128 256
	${INSTALL_DATA} ${WRKSRC}/XCode/Oricutron/Oricutron/Images.xcassets/AppIcon.appiconset/logo${i}.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps/${PKGBASE}.png
.endfor

.include "../../devel/cmake/build.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
