# $NetBSD: Makefile,v 1.8 2023/10/24 22:10:45 wiz Exp $

R_PKGNAME=	openssl
R_PKGVER=	2.0.5
PKGREVISION=	1
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Toolkit for encryption, signatures and certificates based on OpenSSL
LICENSE=	mit

DEPENDS+=	R-askpass>=1.1:../../security/R-askpass

TEST_DEPENDS+=	R-bslib-[0-9]*:../../www/R-bslib
TEST_DEPENDS+=	R-htmltools-[0-9]*:../../textproc/R-htmltools
TEST_DEPENDS+=	R-jose-[0-9]*:../../security/R-jose
TEST_DEPENDS+=	R-jquerylib-[0-9]*:../../www/R-jquerylib
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-sodium-[0-9]*:../../security/R-sodium
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-tinytex-[0-9]*:../../print/R-tinytex

USE_TOOLS+=	bash
USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
