# $NetBSD: Makefile,v 1.1 2019/08/09 19:10:28 brook Exp $

R_PKGNAME=	rcmdcheck
R_PKGVER=	1.3.3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Run 'R CMD check' from 'R' and capture results
LICENSE=	mit

DEPENDS+=	R-callr>=3.1.1.9000:../../devel/R-callr
DEPENDS+=	R-cli>=1.1.0:../../devel/R-cli
DEPENDS+=	R-crayon>=1.3.4:../../devel/R-crayon
DEPENDS+=	R-desc>=1.2.0:../../devel/R-desc
DEPENDS+=	R-pkgbuild>=1.0.4:../../devel/R-pkgbuild
DEPENDS+=	R-rprojroot>=1.3.2:../../devel/R-rprojroot
DEPENDS+=	R-sessioninfo>=1.1.1:../../devel/R-sessioninfo
DEPENDS+=	R-withr>=2.1.2:../../devel/R-withr
DEPENDS+=	R-prettyunits>=1.0.2:../../math/R-prettyunits
DEPENDS+=	R-digest>=0.6.20:../../security/R-digest
DEPENDS+=	R-xopen>=1.0.0:../../sysutils/R-xopen

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
