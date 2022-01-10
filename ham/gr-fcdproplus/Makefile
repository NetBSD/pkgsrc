# $NetBSD: Makefile,v 1.23 2022/01/10 01:46:37 ryoon Exp $

DISTNAME=		gr-fcdproplus-3.8.0.20200811
PKGREVISION=		1
CATEGORIES=		ham
MASTER_SITES=		${MASTER_SITE_GITHUB:=dl1ksv/}
GITHUB_TAG=		575fcafbb8f36dc11d95a305f331660612a44596

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/dl1ksv/gr-fcdproplus
COMMENT=		Addon for funcube dongle pro+ to GNU Radio
LICENSE=		gnu-gpl-v2

BUILD_DEPENDS+= swig3-[0-9]*:../../devel/swig3

USE_LANGUAGES=		c c++
USE_TOOLS=		cmake
USE_CMAKE=		yes

CFLAGS+=		-I${PREFIX}/include/libusb-1.0
CXXFLAGS+=		-I${PREFIX}/include/libusb-1.0

# Suppress warning for developer
CMAKE_ARGS+=		-Wno-dev
CMAKE_ARGS+=		-DGNURADIO_RUNTIME_INCLUDE_DIRS=${PREFIX}/include
PLIST_SUBST+=		PYSITELIB=${PYSITELIB}
CMAKE_ARGS+=		-DENABLE_DOXYGEN=OFF
#CMAKE_ARGS+=		-DDOXY_FILE_PATH=${PREFIX}/share/gnuradio/modtool/templates/gr-newmod/docs/doxygen

.include	"../../devel/boost-headers/buildlink3.mk"
.include	"../../devel/boost-libs/buildlink3.mk"
.include	"../../devel/libusb1/buildlink3.mk"
.include	"../../lang/python/application.mk"
.include	"../../lang/python/pyversion.mk"
.include 	"../../ham/gnuradio-core/buildlink3.mk"
.include 	"../../ham/gnuradio-utils/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
