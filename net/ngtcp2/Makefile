# $NetBSD: Makefile,v 1.36 2026/04/16 12:35:12 adam Exp $

DISTNAME=	ngtcp2-1.22.1
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
