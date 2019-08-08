# $NetBSD: Makefile,v 1.2 2019/08/08 19:53:56 brook Exp $

R_PKGNAME=	cellranger
R_PKGVER=	1.1.0
CATEGORIES=	textproc

MAINTAINER=	bacon@NetBSD.org
COMMENT=	Translate spreadsheet cell ranges to rows and columns
LICENSE=	mit

DEPENDS+=	R-rematch>=1.0.1:../../devel/R-rematch
DEPENDS+=	R-tibble>=2.1.3:../../math/R-tibble

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
