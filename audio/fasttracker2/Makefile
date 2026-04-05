# $NetBSD: Makefile,v 1.146 2026/04/05 08:18:28 fox Exp $

DISTNAME=	fasttracker2-2.13
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=8bitbubsy/}
GITHUB_PROJECT=	ft2-clone
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	fox@NetBSD.org
HOMEPAGE=	https://16-bits.org/
COMMENT=	Portable Fasttracker II clone in C using SDL 2
LICENSE=	modified-bsd AND cc-by-nc-sa-v4.0-license

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

FORCE_C_STD=	gnu99

CMAKE_CONFIGURE_ARGS+=	-DEXTERNAL_LIBFLAC:BOOL=ON

LDFLAGS+=	${BUILDLINK_LDADD.iconv}

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/appdata
INSTALLATION_DIRS+=	share/pixmaps

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/release/other/ft2-clone \
		${DESTDIR}${PREFIX}/bin/${PKGBASE}
	${INSTALL_DATA} ${FILESDIR}/fasttracker2.desktop \
		${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${FILESDIR}/fasttracker2.appdata.xml \
		${DESTDIR}${PREFIX}/share/appdata
	${INSTALL_DATA} ${WRKSRC}/src/gfxdata/icon/ft2-clone.png \
	    ${DESTDIR}${PREFIX}/share/pixmaps/fasttracker2.png

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Linux"
.  include "../../audio/alsa-lib/buildlink3.mk"
.endif
.include "../../audio/flac/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
PTHREAD_OPTS?=	require
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
