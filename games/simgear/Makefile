# $NetBSD: Makefile,v 1.89 2019/07/01 04:07:48 ryoon Exp $

DISTNAME=	simgear-2018.3.2
PKGREVISION=	5
CATEGORIES=	games devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=flightgear/release-2018.3/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://home.flightgear.org/
COMMENT=	Simulator Construction Tools
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_CMAKE=		yes

CONFIGURE_DIRS=		sgbuild
BUILD_DIRS=		sgbuild
CMAKE_ARG_PATH=		..

CMAKE_ARGS+=		-DCMAKE_BUILD_TYPE=Release

LDFLAGS.SunOS+=		-lsocket -lnsl

# The cmake script warns against building in the source directory.
pre-configure:
	cd ${WRKSRC} && ${MKDIR} sgbuild

.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/osg/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
