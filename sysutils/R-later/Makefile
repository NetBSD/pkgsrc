# $NetBSD: Makefile,v 1.3 2019/12/31 12:08:15 mef Exp $

R_PKGNAME=	later
R_PKGVER=	1.0.0
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
