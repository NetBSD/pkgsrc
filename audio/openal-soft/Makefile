# $NetBSD: Makefile,v 1.39 2024/01/30 14:21:33 ryoon Exp $

DISTNAME=	openal-soft-1.23.1
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	https://openal-soft.org/openal-releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://openal-soft.org/
COMMENT=	Software implementation of the OpenAL 3D audio API
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config gmake

USE_CXX_FEATURES+=	c++20

PKGCONFIG_OVERRIDE+=	openal.pc.in
PKG_SYSCONFSUBDIR=	openal

CMAKE_ARGS+=	-DALSOFT_EXAMPLES=OFF
CMAKE_ARGS+=	-DALSOFT_UTILS=ON
CMAKE_ARGS+=	-DALSOFT_NO_CONFIG_UTIL=ON
CMAKE_ARGS+=	-DALSOFT_RTKIT=OFF

CFLAGS+=	-DSYS_CONF_DIR="\"${PKG_SYSCONFDIR}\""
CFLAGS.NetBSD+=	-D_NETBSD_SOURCE
CFLAGS.SunOS+=	-D__EXTENSIONS__

BUILDLINK_TRANSFORM+=		rm:-Wall
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=${WRKSRC}/libopenal.version

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

.include "../../devel/cmake/build.mk"
.include "../../audio/libmysofa/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
