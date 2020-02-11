# $NetBSD: Makefile,v 1.2 2020/02/11 00:00:16 mef Exp $

R_PKGNAME=	pkgbuild
R_PKGVER=	1.0.6
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Find tools needed to build R packages
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-callr>=3.2.0:../../devel/R-callr
DEPENDS+=	R-cli>=1.1.0:../../devel/R-cli
DEPENDS+=	R-crayon>=1.3.4:../../devel/R-crayon
DEPENDS+=	R-desc>=1.2.0:../../devel/R-desc
DEPENDS+=	R-rprojroot>=1.3.2:../../devel/R-rprojroot
DEPENDS+=	R-withr>=2.1.2:../../devel/R-withr
DEPENDS+=	R-prettyunits>=1.0.2:../../math/R-prettyunits

# need for make test
USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
