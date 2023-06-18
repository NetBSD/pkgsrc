# $NetBSD: Makefile,v 1.1 2023/06/18 14:21:13 mef Exp $

R_PKGNAME=	cellranger
R_PKGVER=	1.1.0

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Translate Spreadsheet Cell Ranges to Rows and Columns
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-rematch>=1.0.1:../../devel/R-rematch
DEPENDS+=	R-tibble>=3.2.1:../../math/R-tibble

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
