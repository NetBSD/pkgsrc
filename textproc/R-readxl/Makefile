# $NetBSD: Makefile,v 1.2 2019/08/08 19:53:57 brook Exp $

R_PKGNAME=	readxl
R_PKGVER=	1.3.1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Read Excel files
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-tibble>=1.3.1:../../math/R-tibble
DEPENDS+=	R-cellranger>=1.1.0:../../textproc/R-cellranger

USE_LANGUAGES+=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../sysutils/R-progress/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
