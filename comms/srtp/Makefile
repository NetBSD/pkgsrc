# $NetBSD: Makefile,v 1.8 2024/08/25 06:18:28 wiz Exp $

DISTNAME=	srtp-2.6.0
CATEGORIES=	comms security
MASTER_SITES=	${MASTER_SITE_GITHUB:=cisco/}
GITHUB_PROJECT=	libsrtp
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cisco/libsrtp
COMMENT=	Secure Real-time Transport Protocol library
LICENSE=	modified-bsd

PKGCONFIG_OVERRIDE=	libsrtp2.pc.in

TEST_TARGET=	test
TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}
# For Darwin
TEST_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}

CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=ON
CMAKE_CONFIGURE_ARGS+=	-DBUILD_WITH_WARNINGS=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_OPENSSL=ON

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../devel/cmake/build.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
