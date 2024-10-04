# $NetBSD: Makefile,v 1.168 2024/10/04 03:49:24 ryoon Exp $

DISTNAME=	simgear-2020.3.11
PKGREVISION=	41
CATEGORIES=	games devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=flightgear/release-${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.flightgear.org/
COMMENT=	Simulator Construction Tools
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=		c c++
USE_CMAKE=		yes

CONFIGURE_DIRS=		sgbuild
BUILD_DIRS=		sgbuild
CMAKE_ARG_PATH=		..

CMAKE_CONFIGURE_ARGS+=		-DCMAKE_BUILD_TYPE=Release
CMAKE_CONFIGURE_ARGS+=		-DSIMGEAR_SHARED=ON
CMAKE_CONFIGURE_ARGS+=		-DSYSTEM_EXPAT=ON
CMAKE_CONFIGURE_ARGS+=		-DSYSTEM_UDNS=ON

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} != "x86_64"
CMAKE_CONFIGURE_ARGS+=		-DENABLE_SIMD=OFF
.endif

LDFLAGS.SunOS+=		-lsocket -lnsl

# The cmake script warns against building in the source directory.
pre-configure:
	cd ${WRKSRC} && ${MKDIR} sgbuild

.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.if ${OPSYS} != "Darwin"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.endif
.include "../../graphics/osg/buildlink3.mk"
.include "../../net/udns/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
