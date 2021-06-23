# $NetBSD: Makefile,v 1.3 2021/06/23 20:00:32 bacon Exp $

R_PKGNAME=	cellranger
R_PKGVER=	1.1.0
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Translate spreadsheet cell ranges to rows and columns
LICENSE=	mit

DEPENDS+=	R-rematch>=1.0.1:../../devel/R-rematch
DEPENDS+=	R-tibble>=2.1.3:../../math/R-tibble

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
