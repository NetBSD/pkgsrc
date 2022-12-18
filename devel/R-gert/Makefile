# $NetBSD: Makefile,v 1.5 2022/12/18 01:53:04 mef Exp $

R_PKGNAME=	gert
R_PKGVER=	1.9.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Simple Git Client for R
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-askpass>=1.1:../../security/R-askpass
DEPENDS+=	R-credentials>=1.2.1:../../security/R-credentials
DEPENDS+=	R-openssl>=2.0.3:../../security/R-openssl
DEPENDS+=	R-rstudioapi>=0.11:../../math/R-rstudioapi
DEPENDS+=	R-zip>=2.1.0:../../archivers/R-zip

TEST_DEPENDS+=	R-spelling-[0-9]*:../../textproc/R-spelling
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../devel/libgit2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
