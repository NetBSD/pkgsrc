# $NetBSD: Makefile,v 1.10 2019/08/08 21:18:43 nia Exp $

DISTNAME=	openal-soft-1.19.1
CATEGORIES=	audio
MASTER_SITES=	https://kcat.strangesoft.net/openal-releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://kcat.strangesoft.net/openal.html
COMMENT=	Software implementation of the OpenAL 3D audio API
LICENSE=	gnu-lgpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

PKG_SYSCONFSUBDIR=openal

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
CMAKE_ARGS+=	-DALSOFT_BACKEND_ALSA:BOOL=OFF
.else
.include "../../audio/alsa-lib/buildlink3.mk"
.endif

CMAKE_ARGS+=	-DALSOFT_REQUIRE_SOLARIS:BOOL=OFF
CMAKE_ARGS+=	-DALSOFT_REQUIRE_SNDIO:BOOL=OFF
CMAKE_ARGS+=	-DALSOFT_REQUIRE_QSA:BOOL=OFF
CMAKE_ARGS+=	-DALSOFT_BACKEND_WAVE:BOOL=ON
CMAKE_ARGS+=	-DALSOFT_UTILS:BOOL=ON
CMAKE_ARGS+=	-DALSOFT_EXAMPLES:BOOL=OFF
CMAKE_ARGS+=	-DALSOFT_BACKEND_JACK:BOOL=OFF
CMAKE_ARGS+=	-DALSOFT_BACKEND_PORTAUDIO:BOOL=OFF
CMAKE_ARGS+=	-DALSOFT_BACKEND_PULSEAUDIO:BOOL=OFF
CMAKE_ARGS+=	-DALSOFT_NO_CONFIG_UTIL:BOOL=ON

.include "../../mk/oss.buildlink3.mk"

.if ${OSS_TYPE} == "none"
CMAKE_ARGS+=	-DALSOFT_REQUIRE_OSS:BOOL=OFF
.else
CMAKE_ARGS+=	-DALSOFT_REQUIRE_OSS:BOOL=ON
.endif

CFLAGS+= -DSYS_CONF_DIR="\"${PKG_SYSCONFDIR}\""
CFLAGS.NetBSD+=	-D_NETBSD_SOURCE
CFLAGS.SunOS+=	-D__EXTENSIONS__

CONF_FILES+= ${PREFIX}/share/openal/alsoftrc.sample ${PKG_SYSCONFDIR}/alsoft.conf

SUBST_CLASSES+=			fix-oss
SUBST_STAGE.fix-oss=		pre-configure
SUBST_MESSAGE.fix-oss=		Fixing default OSS device references.
SUBST_FILES.fix-oss=		Alc/backends/oss.c
SUBST_SED.fix-oss=		-e 's,/dev/dsp,${DEVOSSSOUND},'

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
