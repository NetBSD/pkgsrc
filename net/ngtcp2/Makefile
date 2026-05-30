# $NetBSD: Makefile,v 1.37 2026/05/30 19:00:52 ryoon Exp $

DISTNAME=	ngtcp2-1.22.1
PKGREVISION=	1
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
.include "../../security/openssl/buildlink3.mk"
.include "../../www/nghttp3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
