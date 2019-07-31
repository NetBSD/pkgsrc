# $NetBSD: Makefile,v 1.1 2019/07/31 13:55:05 brook Exp $

CATEGORIES=	textproc R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/readxl/
COMMENT=	Read Excel files
LICENSE=	gnu-gpl-v3

R_PKGNAME=	readxl
R_PKGVER=	1.3.1

DEPENDS+=	R-tibble>=1.3.1:../../math/R-tibble
DEPENDS+=	R-cellranger>=1.1.0:../../textproc/R-cellranger

USE_LANGUAGES+=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../sysutils/R-progress/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
