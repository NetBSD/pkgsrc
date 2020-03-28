# $NetBSD: Makefile,v 1.15 2020/03/28 18:00:47 nia Exp $

DISTNAME=	openal-soft-1.20.1
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://kcat.strangesoft.net/openal-releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://kcat.strangesoft.net/openal.html
COMMENT=	Software implementation of the OpenAL 3D audio API
LICENSE=	gnu-lgpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++11
USE_TOOLS+=	pkg-config gmake

# https://github.com/kcat/openal-soft/issues/347
GCC_REQD+=	5

MAKE_JOBS_SAFE=		no

PKG_SYSCONFSUBDIR=	openal

CMAKE_ARGS+=	-DALSOFT_EXAMPLES=OFF
CMAKE_ARGS+=	-DALSOFT_NO_CONFIG_UTIL=ON

CFLAGS+=	-DSYS_CONF_DIR="\"${PKG_SYSCONFDIR}\""
CFLAGS.NetBSD+=	-D_NETBSD_SOURCE
CFLAGS.SunOS+=	-D__EXTENSIONS__

CONF_FILES+=	${PREFIX}/share/openal/alsoftrc.sample ${PKG_SYSCONFDIR}/alsoft.conf

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" || ${OPSYS} == "NetBSD"
CMAKE_ARGS+=		-DALSOFT_BACKEND_SOLARIS=ON
CMAKE_ARGS+=		-DALSOFT_REQUIRE_SOLARIS=ON
.endif

.include "../../mk/oss.buildlink3.mk"

.if ${OSS_TYPE} != "none"
CMAKE_ARGS+=		-DALSOFT_BACKEND_OSS=ON
CMAKE_ARGS+=		-DALSOFT_REQUIRE_OSS=ON
SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	pre-configure
SUBST_MESSAGE.oss=	Fixing default OSS device references.
SUBST_FILES.oss=	alc/backends/oss.cpp
SUBST_SED.oss=		-e 's,/dev/dsp,${DEVOSSAUDIO},'
.endif


PKGCONFIG_OVERRIDE+=	openal.pc.in

.include "options.mk"
.include "../../audio/libmysofa/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
