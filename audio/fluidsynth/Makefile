# $NetBSD: Makefile,v 1.63 2022/07/17 08:26:57 wiz Exp $

DISTNAME=	fluidsynth-2.2.8
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=FluidSynth/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.fluidsynth.org/
COMMENT=	Software synthesizer based on SoundFont2
LICENSE=	gnu-lgpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

CHECK_PORTABILITY_SKIP+=	test-android/convert-tests.sh

CMAKE_ARGS+=	-DMAN_INSTALL_DIR=${PREFIX}/${PKGMANDIR}/man1
CMAKE_ARGS+=	-DLIB_SUFFIX=""
CMAKE_ARGS+=	-Denable-framework=OFF

PKGCONFIG_OVERRIDE=	fluidsynth.pc.in

LDFLAGS.SunOS+=		-lsocket

.include "../../mk/oss.buildlink3.mk"

.if ${OSS_TYPE} != "none"
LDFLAGS+=		${LIBOSSAUDIO}
SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	pre-configure
SUBST_MESSAGE.oss=	Correcting the path to the OSS device.
SUBST_FILES.oss+=	src/drivers/fluid_oss.c
SUBST_SED.oss+=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
SUBST_SED.oss+=		-e "s,/dev/midi,${DEVOSSMIDI},g"
.endif

# mlock on SunOS has a caddr_t argument rather than void *
BUILDLINK_TRANSFORM+=	rm:-Werror=incompatible-pointer-types

.include "options.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
