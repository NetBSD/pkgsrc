# $NetBSD: Makefile,v 1.2 2019/09/07 08:38:27 maya Exp $

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
.include "../../devel/R-BH/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
