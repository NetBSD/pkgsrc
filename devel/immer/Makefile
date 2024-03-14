# $NetBSD: Makefile,v 1.1 2024/03/14 19:24:15 markd Exp $

DISTNAME=	immer-0.8.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=arximboldi/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sinusoid.es/immer
COMMENT=	Postmodern immutable and persistent data structures for C++
LICENSE=	boost-license

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
