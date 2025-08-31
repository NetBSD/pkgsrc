# $NetBSD: Makefile,v 1.1 2025/08/31 19:15:04 wiz Exp $

DISTNAME=	docopt.cpp-0.6.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=docopt/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/docopt/docopt.cpp/
COMMENT=	C++11 port of docopt
LICENSE=	boost-license AND mit

USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	docopt.pc.in

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
