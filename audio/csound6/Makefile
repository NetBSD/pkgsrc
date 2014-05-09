# $NetBSD: Makefile,v 1.3 2014/05/09 07:36:53 wiz Exp $

DISTNAME=		Csound${CSOUND_VERSION}
PKGNAME=		csound6-${CSOUND_VERSION}
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=csound/csound6/Csound6.02/}
WRKSRC=			${WRKDIR}/Csound${CSOUND_VERSION}

MAINTAINER=		mrg@eterna.com.au
HOMEPAGE=		http://sourceforge.net/projects/csound/
COMMENT=		Software synthesizer and sequencer
LICENSE=		gnu-lgpl-v2.1 # or later

CSOUND_VERSION=		6.02
USE_LANGUAGES=		c c++
USE_TOOLS+=		bison
CFLAGS+=		-g -D__PKGSRC_PREFIX__=\"${PREFIX}/\" -DBETA
USE_CMAKE=		yes
CMAKE_ARGS+=		-DUSE_PORTAUDIO:BOOL=OFF
CMAKE_ARGS+=		-DBUILD_RELEASE=1 -DCMAKE_BUILD_TYPE=Release 
# CMAKE_INSTALL_RPATH doesn't work for some reason, so do it here.
LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/csound6

# Has long files our tar doesn't understand.
EXTRACT_USING=		gtar

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 5.01

INSTALLATION_DIRS=	bin

CHECK_PORTABILITY_SKIP+=	installer/misc/makedeb.sh \
				installer/macosx/release-build-10.8.sh \
				frontends/max_csound_tilde/installer/build-installer.sh

.include "../../mk/bsd.prefs.mk"

post-install:
	cd ${DESTDIR}${PREFIX} && ${LN} -s ../lib/csound6/csound bin/csound6

.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/portaudio/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
PYTHON_FOR_BUILD_ONLY=	yes
.include "../../lang/python/application.mk"
.include "../../x11/fltk/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
