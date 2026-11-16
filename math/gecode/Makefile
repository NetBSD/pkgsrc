# $NetBSD: Makefile,v 1.1 2026/11/16 22:58:51 alnsn Exp $

DISTNAME=	gecode-6.6.0
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=Gecode/}
GITHUB_PROJECT=	gecode
GITHUB_TAG=	release-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Gecode/gecode/
COMMENT=	Generic Constraint Development Environment
LICENSE=	mit

USE_LANGUAGES=		c c++
USE_CXX_FEATURES+=	c++17

WRKSRC=		${WRKDIR}/gecode-${GITHUB_TAG}

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
