# $NetBSD: Makefile,v 1.1 2019/07/31 13:42:34 brook Exp $

CATEGORIES=	textproc R

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://cran.r-project.org/web/packages/cellranger/index.html
COMMENT=	Translate spreadsheet cell ranges to rows and columns
LICENSE=	mit

R_PKGNAME=	cellranger
R_PKGVER=	1.1.0

DEPENDS+=	R-rematch>=1.0.1:../../devel/R-rematch
DEPENDS+=	R-tibble>=2.1.3:../../math/R-tibble

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
