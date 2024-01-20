# $NetBSD: Makefile,v 1.6 2024/01/20 04:03:23 mef Exp $

R_PKGNAME=	gert
R_PKGVER=	2.0.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Simple Git Client for R
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-askpass>=1.1:../../security/R-askpass
DEPENDS+=	R-credentials>=1.2.1:../../security/R-credentials
DEPENDS+=	R-openssl>=2.0.3:../../security/R-openssl
DEPENDS+=	R-rstudioapi>=0.11:../../math/R-rstudioapi
DEPENDS+=	R-zip>=2.1.0:../../archivers/R-zip

TEST_DEPENDS+=	R-askpass-[0-9]*:../../security/R-askpass
TEST_DEPENDS+=	R-credentials-[0-9]*:../../security/R-credentials
TEST_DEPENDS+=	R-openssl-[0-9]*:../../security/R-openssl
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-rstudioapi-[0-9]*:../../math/R-rstudioapi
TEST_DEPENDS+=	R-spelling-[0-9]*:../../textproc/R-spelling
TEST_DEPENDS+=	R-sys-[0-9]*:../../sysutils/R-sys
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-zip-[0-9]*:../../archivers/R-zip

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../devel/libgit2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
