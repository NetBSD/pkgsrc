# $NetBSD: Makefile,v 1.2 2006/09/04 14:17:51 ben Exp $
#

DISTNAME=		Csound${CSOUND_VERSION}_src
PKGNAME=		csound5-${CSOUND_VERSION}
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=csound/}
WRKSRC=			${WRKDIR}/Csound${CSOUND_VERSION}

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		http://sourceforge.net/projects/csound/
COMMENT=		Software synthesizer and sequencer

CSOUND_VERSION=		5.01
USE_LANGUAGES=		c c++
CFLAGS+=		-g -D__PKGSRC_PREFIX__=${PREFIX}/ -DBETA
BUILD_DEPENDS+=         scons>=0.96:../../devel/scons
NOT_FOR_PLATFORM=	*-*-alpha *-*-sparc64	# Severe LP64 problems
SCONS=			${PREFIX}/bin/scons
SCONS_ARGS=		-C ${WRKSRC} prefix=${PREFIX}
SCONS_ARGS+=		buildDSSI=0 buildLoris=0 buildRelease=1
SCONS_ARGS+=		useALSA=0 useJack=0 useOSC=0 usePortMIDI=0
SCONS_ARGS+=		usePortAudio=0
SCONS_ENV_FILE=		${WRKDIR}/ugly-pkgsrc-scons-hack.txt

do-build:
	${ECHO} ${MAKE_ENV:Q} >${SCONS_ENV_FILE}
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SCONS} ${SCONS_ARGS}

do-install:
	cd ${WRKSRC} && SCONS_ENV="`${CAT} ${SCONS_ENV_FILE}`" && \
		eval "${SETENV} $${SCONS_ENV} ${SCONS} ${SCONS_ARGS} install"
	cd ${PREFIX} && ${LN} -s ../lib/csound5/csound bin/csound5

.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../devel/swig/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python24/buildlink3.mk"
.include "../../x11/fltk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
