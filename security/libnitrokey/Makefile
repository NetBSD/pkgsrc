# $NetBSD: Makefile,v 1.6 2023/10/29 22:19:17 adam Exp $

DISTNAME=	libnitrokey-3.8
PKGREVISION=	3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=Nitrokey/}
GITHUB_PROJECT=	libnitrokey
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://github.com/Nitrokey/libnitrokey/
COMMENT=	Library to communicate with Nitrokey devices
LICENSE=	gnu-lgpl-v3

USE_CXX_FEATURES=	c++14
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

.include "options.mk"

# actual hardware tests
#   1. require a connected Nitrokey
#   2. may kill data on your Nitrokey
# hence the main testsuite is disabled
CMAKE_ARGS+=	-DCOMPILE_TESTS=OFF

CMAKE_ARGS+=	-DHIDAPI_LIBUSB_INCLUDEDIR=${BUILDLINK_PREFIX.libhidapi}/include/hidapi/
CMAKE_ARGS+=	-DHIDAPI_LIBUSB_LIBDIR=${BUILDLINK_PREFIX.libhidapi}/lib/
CMAKE_ARGS+=	-DCMAKE_INSTALL_UDEVRULESDIR=${PREFIX}/lib/udev/rules.d/

TEST_TARGET=	test

.include "../../comms/libhidapi/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/libusb1/buildlink3.mk"
.if ${OPSYS} == "Linux"
.include "../../sysutils/libudev/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
