# $NetBSD: Makefile,v 1.27 2022/08/11 05:08:48 gutteridge Exp $

DISTNAME=	freedv-1.4.2
PKGREVISION=	4
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_GITHUB:=drowe67/}
GITHUB_PROJECT=	freedv-gui
GITHUB_TAG=	bb9558cc496b7b253fb54bb28486b0bcd7516ae5

MAINTAINER=	dbj@NetBSD.org
HOMEPAGE=	https://freedv.org/
COMMENT=	FreeDV: HF Digital Voice for Radio Amateurs
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

USE_CMAKE=	yes
CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	icons
.if ${OPSYS} != "Darwin"
PLIST.icons=	yes
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.else
post-build:
	cd ${WRKSRC}/build/src && \
		ver="$$(sed -n -e 's/^\#define FREEDV_VERSION "\(.*\)"$$/\1/p' version.h)" && \
		/usr/libexec/PlistBuddy \
			-c 'Set CFBundleShortVersionString "'"$${ver}"'"' \
			-c 'Set CFBundleExecutable FreeDV' \
			FreeDV.app/Contents/info.plist
INSTALLATION_DIRS+=	Applications
USE_TOOLS+=	pax
post-install:
	cd ${WRKSRC}/build/src && \
		pax -rw -pp -pm FreeDV.app ${DESTDIR}${PREFIX}/Applications
.endif
pre-configure:
	${MKDIR} ${WRKSRC}/build

.include "../../ham/codec2/buildlink3.mk"
.include "../../ham/lpcnetfreedv/buildlink3.mk"
.include "../../ham/hamlib/buildlink3.mk"
# freedv 1.4.2 seems to only use included static sox
#.include "../../audio/sox/buildlink3.mk"
.include "../../audio/speexdsp/buildlink3.mk"
.include "../../audio/portaudio/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
