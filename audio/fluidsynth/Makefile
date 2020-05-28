# $NetBSD: Makefile,v 1.39 2020/05/28 10:25:58 nia Exp $

DISTNAME=	fluidsynth-2.1.3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=FluidSynth/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fluidsynth.org/
COMMENT=	Software synthesizer based on SoundFont2
LICENSE=	gnu-lgpl-v2

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config

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

.include "options.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
