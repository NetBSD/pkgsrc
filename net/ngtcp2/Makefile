# $NetBSD: Makefile,v 1.6 2023/04/26 19:42:11 wiz Exp $

DISTNAME=	ngtcp2-0.15.0
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
.include "../../mk/bsd.pkg.mk"
