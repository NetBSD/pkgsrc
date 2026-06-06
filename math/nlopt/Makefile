# $NetBSD: Makefile,v 1.10 2026/06/06 05:36:07 adam Exp $

DISTNAME=	nlopt-2.11.0
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=stevengj/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://nlopt.readthedocs.io/en/latest/
COMMENT=	Nonlinear optimization library
LICENSE=	gnu-lgpl-v2.1 OR mit

USE_CXX_FEATURES=	c++11
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

CMAKE_CONFIGURE_ARGS+=	-DNLOPT_PYTHON=OFF

.include "../../devel/cmake/build.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
