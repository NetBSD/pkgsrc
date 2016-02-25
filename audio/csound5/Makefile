# $NetBSD: Makefile,v 1.37 2016/02/25 10:15:45 jperkin Exp $

DISTNAME=		Csound${CSOUND_VERSION}
PKGNAME=		csound5-${CSOUND_VERSION}
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=csound/csound5/csound5.19/}
WRKSRC=			${WRKDIR}/Csound${CSOUND_VERSION}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sourceforge.net/projects/csound/
COMMENT=		Software synthesizer and sequencer
LICENSE=		gnu-lgpl-v2.1 # or later

CSOUND_VERSION=		5.19.01
USE_LANGUAGES=		c c++
USE_TOOLS+=		bison
CFLAGS+=		-D__PKGSRC_PREFIX__=${PREFIX}/ -DBETA
BUILD_DEPENDS+=		scons>=0.96:../../devel/scons
SCONS=			${PREFIX}/bin/scons
SCONS_ARGS=		-C ${WRKSRC} prefix=${PREFIX}
SCONS_ARGS+=		buildDSSI=0 buildLoris=0 buildRelease=1
SCONS_ARGS+=		useALSA=0 useJack=0 useOSC=0 usePortMIDI=0
SCONS_ARGS+=		usePortAudio=0
SCONS_ARGS+=		buildInterfaces=0

# Has long files our tar doesn't understand.
EXTRACT_USING=		gtar

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # not yet ported as of 5.01

INSTALLATION_DIRS=	bin

CHECK_PORTABILITY_SKIP+=	installer/misc/makedeb.sh

SUBST_CLASSES.SunOS+=	strip
SUBST_STAGE.strip=	pre-build
SUBST_FILES.strip=	install.py installer/misc/mkpackage.py
SUBST_SED.strip=	-e 's/--strip-unneeded//g'

do-build:
	cd ${WRKSRC} && ${TOOLS_PATH.bison} -d -o frontends/beats/beats.tab.c frontends/beats/beats.y
	cd ${WRKSRC} && if [ ! -f custom.py ]; then cp custom.py.mkg custom.py; fi
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SCONS} ${SCONS_ARGS}

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${INSTALL_ENV} ${PYTHONBIN} \
		install.py --prefix=${PREFIX} --instdir=${DESTDIR}
	cd ${DESTDIR}${PREFIX} && ${LN} -s ../lib/csound5/csound bin/csound5

.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
PYTHON_FOR_BUILD_ONLY=	yes
.include "../../lang/python/application.mk"
.include "../../x11/fltk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
