# $NetBSD: Makefile,v 1.4 2021/09/04 12:34:42 mef Exp $

R_PKGNAME=	DT
R_PKGVER=	0.19
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Wrapper of the JavaScript Library 'DataTables'
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-magrittr>=1.5:../../devel/R-magrittr
DEPENDS+=	R-promises>=1.0.1:../../parallel/R-promises
DEPENDS+=	R-htmltools>=0.3.6:../../textproc/R-htmltools
DEPENDS+=	R-jsonlite>=0.9.16:../../textproc/R-jsonlite
DEPENDS+=	R-htmlwidgets>=1.3:../../www/R-htmlwidgets
DEPENDS+=	R-crosstalk-[0-9]*:../../textproc/R-crosstalk

TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
