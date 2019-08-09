# $NetBSD: Makefile,v 1.1 2019/08/09 16:22:30 brook Exp $

R_PKGNAME=	tidyselect
R_PKGVER=	0.2.5
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Select from a set of strings
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-glue>=1.3.0:../../devel/R-glue
DEPENDS+=	R-purrr>=0.3.2:../../devel/R-purrr
DEPENDS+=	R-rlang>=0.2.2:../../devel/R-rlang

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
