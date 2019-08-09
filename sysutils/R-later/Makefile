# $NetBSD: Makefile,v 1.1 2019/08/09 20:24:22 brook Exp $

R_PKGNAME=	later
R_PKGVER=	0.8.0
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Utilities for delaying function execution
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-rlang>=0.4.0:../../devel/R-rlang

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
