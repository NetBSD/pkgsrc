# $NetBSD: Makefile,v 1.28 2022/07/03 16:01:00 wiz Exp $

DISTNAME=	openal-soft-1.22.1
CATEGORIES=	audio
MASTER_SITES=	https://openal-soft.org/openal-releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://openal-soft.org/
COMMENT=	Software implementation of the OpenAL 3D audio API
LICENSE=	gnu-lgpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++14
USE_TOOLS+=	pkg-config gmake

# https://github.com/kcat/openal-soft/issues/347
GCC_REQD+=	5

PKGCONFIG_OVERRIDE+=	openal.pc.in
PKG_SYSCONFSUBDIR=	openal

CMAKE_ARGS+=	-DALSOFT_EXAMPLES=OFF
CMAKE_ARGS+=	-DALSOFT_UTILS=ON
CMAKE_ARGS+=	-DALSOFT_NO_CONFIG_UTIL=ON
CMAKE_ARGS+=	-DALSOFT_RTKIT=OFF

CFLAGS+=	-DSYS_CONF_DIR="\"${PKG_SYSCONFDIR}\""
CFLAGS.NetBSD+=	-D_NETBSD_SOURCE
CFLAGS.SunOS+=	-D__EXTENSIONS__

BUILDLINK_TRANSFORM+=	rm:-Wall

CONF_FILES+=	${PREFIX}/share/openal/alsoftrc.sample ${PKG_SYSCONFDIR}/alsoft.conf

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" || ${OPSYS} == "NetBSD"
CMAKE_ARGS+=	-DALSOFT_BACKEND_SOLARIS=ON
CMAKE_ARGS+=	-DALSOFT_REQUIRE_SOLARIS=ON
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

.include "options.mk"

post-install:
	${RM} ${DESTDIR}${PREFIX}/include/AL/al.h.orig

.include "../../audio/libmysofa/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
