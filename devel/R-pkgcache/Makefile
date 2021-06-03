# $NetBSD: Makefile,v 1.5 2021/06/03 21:01:07 mef Exp $

R_PKGNAME=	pkgcache
R_PKGVER=	1.2.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Cache 'CRAN'-Like Metadata and R Packages
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-assertthat>=0.2.1:../../devel/R-assertthat
DEPENDS+=	R-callr>=2.0.4.9000:../../devel/R-callr
DEPENDS+=	R-cli>=2.0.0:../../devel/R-cli
DEPENDS+=	R-glue>=1.4.1:../../devel/R-glue
DEPENDS+=	R-rappdirs>=0.3.1:../../devel/R-rappdirs
DEPENDS+=	R-rlang>=0.4.9:../../devel/R-rlang
DEPENDS+=	R-uuid>=0.1.2:../../devel/R-uuid
DEPENDS+=	R-prettyunits>=1.0.2:../../math/R-prettyunits
DEPENDS+=	R-tibble>=2.1.3:../../math/R-tibble
DEPENDS+=	R-digest>=0.6.25:../../security/R-digest
DEPENDS+=	R-processx>=3.3.0.9001:../../sysutils/R-processx
DEPENDS+=	R-curl>=3.2:../../www/R-curl
DEPENDS+=	R-filelock-[0-9]*:../../devel/R-filelock
DEPENDS+=	R-jsonlite-[0-9]*:../../textproc/R-jsonlite

# Packages suggested but not available: 'debugme', 'webfakes'
#TEST_DEPENDS+=	R-debugme-[0-9]*:


USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
