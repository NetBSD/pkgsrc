# $NetBSD: Makefile,v 1.4 2026/09/02 19:00:57 wiz Exp $

DISTNAME=	openal-soft-1.19.1
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	https://openal-soft.org/openal-releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://openal-soft.org/
COMMENT=	Software implementation of the OpenAL 3D audio API
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake pkg-config

PKGCONFIG_OVERRIDE+=	openal.pc.in
PKG_SYSCONFSUBDIR=	openal

CMAKE_CONFIGURE_ARGS+=	-DALSOFT_EXAMPLES=OFF
CMAKE_CONFIGURE_ARGS+=	-DALSOFT_UTILS=ON
CMAKE_CONFIGURE_ARGS+=	-DALSOFT_NO_CONFIG_UTIL=ON
CMAKE_CONFIGURE_ARGS+=	-DALSOFT_RTKIT=OFF

CFLAGS+=	-DSYS_CONF_DIR="\"${PKG_SYSCONFDIR}\""
CFLAGS.NetBSD+=	-D_NETBSD_SOURCE
CFLAGS.SunOS+=	-D__EXTENSIONS__

BUILDLINK_TRANSFORM+=		rm:-Wall
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=${WRKSRC}/libopenal.version

CONF_FILES+=	${PREFIX}/share/openal/alsoftrc.sample ${PKG_SYSCONFDIR}/alsoft.conf

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" || ${OPSYS} == "NetBSD"
CMAKE_CONFIGURE_ARGS+=	-DALSOFT_BACKEND_SOLARIS=ON
CMAKE_CONFIGURE_ARGS+=	-DALSOFT_REQUIRE_SOLARIS=ON
.endif

.include "../../mk/oss.buildlink3.mk"

.if ${OSS_TYPE} != "none"
CMAKE_CONFIGURE_ARGS+=	-DALSOFT_BACKEND_OSS=ON
CMAKE_CONFIGURE_ARGS+=	-DALSOFT_REQUIRE_OSS=ON
SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	pre-configure
SUBST_MESSAGE.oss=	Fixing default OSS device references.
SUBST_FILES.oss=	Alc/backends/oss.c
SUBST_SED.oss=		-e 's,/dev/dsp,${DEVOSSAUDIO},'
.endif

.include "options.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
