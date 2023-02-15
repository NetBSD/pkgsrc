# $NetBSD: Makefile,v 1.5 2023/02/15 12:23:30 adam Exp $

DISTNAME=	srtp-2.5.0
CATEGORIES=	comms security
MASTER_SITES=	${MASTER_SITE_GITHUB:=cisco/}
GITHUB_PROJECT=	libsrtp
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cisco/libsrtp
COMMENT=	Secure Real-time Transport Protocol library
LICENSE=	modified-bsd

PKGCONFIG_OVERRIDE=	libsrtp2.pc.in
TEST_TARGET=		test

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON
CMAKE_ARGS+=	-DBUILD_WITH_WARNINGS=OFF
CMAKE_ARGS+=	-DENABLE_OPENSSL=ON

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../devel/cmake/build.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
