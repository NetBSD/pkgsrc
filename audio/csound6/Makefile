# $NetBSD: Makefile,v 1.48 2020/03/26 12:04:11 nia Exp $

DISTNAME=		csound-${CSOUND_VERSION}
PKGNAME=		csound6-${CSOUND_VERSION}
PKGREVISION=		4
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
USE_TOOLS+=		bison flex
CFLAGS+=		-g -D__PKGSRC_PREFIX__=\"${PREFIX}/\" -DBETA
USE_CMAKE=		yes
CMAKE_ARGS+=		-DBUILD_RELEASE=1
CMAKE_ARGS+=		-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=		-DBUILD_HDF5_OPCODES=OFF
# CMAKE_INSTALL_RPATH doesn't work for some reason, so do it here.
LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/csound6

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 5.01

INSTALLATION_DIRS=	bin

CHECK_PORTABILITY_SKIP+=	installer/misc/makedeb.sh \
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
		${LN} -s ../lib/csound6/csound bin/csound6

.include "options.mk"
.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../x11/fltk13/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
