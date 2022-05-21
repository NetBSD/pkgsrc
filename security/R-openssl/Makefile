# $NetBSD: Makefile,v 1.6 2022/05/21 12:48:58 mef Exp $

R_PKGNAME=	openssl
R_PKGVER=	2.0.1
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Toolkit for encryption, signatures and certificates based on OpenSSL
LICENSE=	mit

DEPENDS+=	R-askpass>=1.1:../../security/R-askpass


# Packages suggested but not available: 'jose', 'sodium'
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-bslib-[0-9]*:../../www/R-bslib
TEST_DEPENDS+=	R-htmltools-[0-9]*:../../textproc/R-htmltools
TEST_DEPENDS+=	R-jquerylib-[0-9]*:../../www/R-jquerylib
TEST_DEPENDS+=	R-tinytex-[0-9]*:../../print/R-tinytex

USE_TOOLS+=	bash
USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
