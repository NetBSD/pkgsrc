# $NetBSD: Makefile,v 1.4 2022/04/19 13:25:30 mef Exp $

R_PKGNAME=	gert
R_PKGVER=	1.6.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Simple Git Client for R
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-zip>=2.1.0:../../archivers/R-zip
DEPENDS+=	R-rstudioapi>=0.11:../../math/R-rstudioapi
DEPENDS+=	R-askpass>=1.1:../../security/R-askpass
DEPENDS+=	R-openssl>=1.4.1:../../security/R-openssl
DEPENDS+=	R-credentials-[0-9]*:../../security/R-credentials

TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-spelling-[0-9]*:../../textproc/R-spelling
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../devel/libgit2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
