# $NetBSD: Makefile,v 1.34 2026/02/26 17:28:55 adam Exp $

DISTNAME=	ngtcp2-1.21.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=ngtcp2/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ngtcp2/ngtcp2
COMMENT=	Implements RFC9000 QUIC protocol
LICENSE=	mit

USE_LANGUAGES=	c c++

# Require QUIC support in OpenSSL. Only needed for examples.
CMAKE_CONFIGURE_ARGS+=	-DENABLE_OPENSSL=OFF

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
