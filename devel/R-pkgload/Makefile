# $NetBSD: Makefile,v 1.1 2019/08/09 19:11:22 brook Exp $

R_PKGNAME=	pkgload
R_PKGVER=	1.0.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Simulate package installation and attach
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-desc>=1.2.0:../../devel/R-desc
DEPENDS+=	R-pkgbuild>=1.0.4:../../devel/R-pkgbuild
DEPENDS+=	R-rlang>=0.4.0:../../devel/R-rlang
DEPENDS+=	R-rprojroot>=1.3.2:../../devel/R-rprojroot
DEPENDS+=	R-withr>=2.1.2:../../devel/R-withr
DEPENDS+=	R-rstudioapi>=0.10:../../math/R-rstudioapi

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
