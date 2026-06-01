# $NetBSD: Makefile,v 1.39 2026/06/01 13:54:34 ryoon Exp $

DISTNAME=	ngtcp2-1.23.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=ngtcp2/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ngtcp2/ngtcp2
COMMENT=	Implements RFC9000 QUIC protocol
LICENSE=	mit

USE_LANGUAGES=	c c++

.include "../../devel/cmake/build.mk"
# SSL_set_quic_tls_cbs() is required.
BUILDLINK_API_DEPENDS.openssl+=	openssl>=3.5.0
.include "../../security/openssl/buildlink3.mk"
.include "../../www/nghttp3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
