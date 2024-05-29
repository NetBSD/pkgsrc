# $NetBSD: Makefile,v 1.87 2024/05/29 16:31:19 adam Exp $

DISTNAME=		csound-${CSOUND_VERSION}
PKGNAME=		csound6-${CSOUND_VERSION}
PKGREVISION=		34
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_GITHUB:=csound/}
GITHUB_PROJECT=		csound

MAINTAINER=		mrg@eterna.com.au
HOMEPAGE=		https://github.com/csound
COMMENT=		Software synthesizer and sequencer
LICENSE=		gnu-lgpl-v2.1 # or later

CSOUND_VERSION=		6.15.0
USE_LANGUAGES=		c c++
USE_TOOLS+=		bison flex
CFLAGS+=		-g -DBETA
CFLAGS+=		-DCS_DEFAULT_PLUGINDIR=\"${PREFIX}/lib/csound/plugins64-6.0\"
USE_CMAKE=		yes
CMAKE_ARGS+=		-DBUILD_RELEASE=1
CMAKE_ARGS+=		-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=		-DBUILD_HDF5_OPCODES=OFF
# CMAKE_INSTALL_RPATH doesn't work for some reason, so do it here.
LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/csound6

INSTALLATION_DIRS=	bin

CHECK_PORTABILITY_SKIP+= \
	Android/build-all.sh \
	installer/misc/makedeb.sh \
	installer/macosx/beta-build.sh \
	installer/macosx/release-build.sh \
	installer/macosx/release-build-10.8.sh \
	installer/macosx/release-build-10.10.sh \
	frontends/max_csound_tilde/installer/build-installer.sh \
	frontends/max_csound_tilde/installer/build-installer-windows.sh

.include "../../mk/bsd.prefs.mk"

post-install:
	cd ${DESTDIR}${PREFIX} && \
		rm -f bin/csound6 && \
		${LN} -s csound bin/csound6

.include "options.mk"

.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/liblo/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../math/eigen3/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/fltk13/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
