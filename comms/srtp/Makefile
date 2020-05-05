# $NetBSD: Makefile,v 1.4 2020/05/05 17:54:39 adam Exp $

DISTNAME=	srtp-2.3.0
CATEGORIES=	comms security
MASTER_SITES=	${MASTER_SITE_GITHUB:=cisco/}
GITHUB_PROJECT=	libsrtp
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cisco/libsrtp
COMMENT=	Secure Real-time Transport Protocol library
LICENSE=	modified-bsd

USE_CMAKE=		yes
USE_TOOLS+=		gmake
PKGCONFIG_OVERRIDE=	libsrtp2.pc.in
TEST_TARGET=		test

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON
CMAKE_ARGS+=	-DENABLE_OPENSSL=ON

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
