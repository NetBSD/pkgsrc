# $NetBSD: Makefile,v 1.2 2023/01/24 18:36:31 wiz Exp $

DISTNAME=	ngtcp2-0.11.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=ngtcp2/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ngtcp2/ngtcp2
COMMENT=	Implements RFC9000 QUIC protocol
LICENSE=	mit

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
