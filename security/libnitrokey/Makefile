# $NetBSD: Makefile,v 1.3 2023/05/17 15:37:07 nikita Exp $

DISTNAME=	libnitrokey-3.8
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=Nitrokey/}
GITHUB_PROJECT=	libnitrokey
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://github.com/Nitrokey/libnitrokey/
COMMENT=	Library to communicate with Nitrokey devices
LICENSE=	gnu-lgpl-v3

USE_TOOLS+=	pkg-config

.include "options.mk"
# depends: libudev-devd ?

# actual hardware tests
#   1. require a connected Nitrokey
#   2. may kill data on your Nitrokey
# hence the main testsuite is disabled
CMAKE_ARGS+=	-DCOMPILE_TESTS=OFF

CMAKE_ARGS+=	-DHIDAPI_LIBUSB_INCLUDEDIR=${BUILDLINK_PREFIX.libhidapi}/include/hidapi/
CMAKE_ARGS+=	-DHIDAPI_LIBUSB_LIBDIR=${BUILDLINK_PREFIX.libhidapi}/lib/

TEST_TARGET=	test
USE_LANGUAGES=	c c++14

.include "../../devel/libusb1/buildlink3.mk"
.include "../../comms/libhidapi/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
