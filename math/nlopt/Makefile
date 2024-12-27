# $NetBSD: Makefile,v 1.6 2024/12/27 17:22:12 adam Exp $

DISTNAME=	nlopt-2.9.1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=stevengj/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ab-initio.mit.edu/nlopt/
COMMENT=	Nonlinear optimization library
LICENSE=	gnu-lgpl-v2.1 OR mit

USE_CXX_FEATURES=	c++11
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

CMAKE_CONFIGURE_ARGS+=	-DNLOPT_PYTHON=OFF

.include "../../devel/cmake/build.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
