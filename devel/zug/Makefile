# $NetBSD: Makefile,v 1.2 2024/04/14 08:35:26 wiz Exp $

DISTNAME=	zug-0.1.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=arximboldi/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sinusoid.es/zug
COMMENT=	Transducers for C++
LICENSE=	boost-license

USE_LANGUAGES=	c c++

.include "../../devel/cmake/build.mk"
.include "../../devel/catch2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
