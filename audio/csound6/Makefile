# $NetBSD: Makefile,v 1.41 2019/11/03 11:51:01 rillig Exp $

DISTNAME=		csound-${CSOUND_VERSION}
PKGNAME=		csound6-${CSOUND_VERSION}
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_GITHUB:=csound/}
GITHUB_PROJECT=		csound

MAINTAINER=		mrg@eterna.com.au
HOMEPAGE=		https://sourceforge.net/projects/csound/
COMMENT=		Software synthesizer and sequencer
LICENSE=		gnu-lgpl-v2.1 # or later

CSOUND_VERSION=		6.13.0
#WRKSRC=		${WRKDIR}/Csound${CSOUND_VERSION}
USE_LANGUAGES=		c c++
USE_TOOLS+=		bison
CFLAGS+=		-g -D__PKGSRC_PREFIX__=\"${PREFIX}/\" -DBETA
USE_CMAKE=		yes
CMAKE_ARGS+=		-DUSE_PULSEAUDIO:BOOL=ON
CMAKE_ARGS+=		-DBUILD_RELEASE=1 -DCMAKE_BUILD_TYPE=Release
# CMAKE_INSTALL_RPATH doesn't work for some reason, so do it here.
LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/csound6

# Has long files our tar doesn't understand.
EXTRACT_USING=		bsdtar

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 5.01

INSTALLATION_DIRS=	bin

CHECK_PORTABILITY_SKIP+=	installer/misc/makedeb.sh \
				installer/macosx/release-build-10.8.sh \
				frontends/max_csound_tilde/installer/build-installer.sh \
				frontends/max_csound_tilde/installer/build-installer-windows.sh

.include "../../mk/bsd.prefs.mk"

post-install:
	cd ${DESTDIR}${PREFIX} && \
		rm -f bin/csound6 && \
		${LN} -s ../lib/csound6/csound bin/csound6

.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
PYTHON_FOR_BUILD_ONLY=	yes
.include "../../lang/python/application.mk"
.include "../../x11/fltk13/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
