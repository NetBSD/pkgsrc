# $NetBSD: Makefile,v 1.130 2022/01/10 01:46:32 ryoon Exp $

DISTNAME=	simgear-2020.3.11
PKGREVISION=	5
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

CMAKE_ARGS+=		-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=		-DSIMGEAR_SHARED=ON
CMAKE_ARGS+=		-DSYSTEM_EXPAT=ON
CMAKE_ARGS+=		-DSYSTEM_UDNS=ON

LDFLAGS.SunOS+=		-lsocket -lnsl

# The cmake script warns against building in the source directory.
pre-configure:
	cd ${WRKSRC} && ${MKDIR} sgbuild

.include "../../mk/bsd.prefs.mk"

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
