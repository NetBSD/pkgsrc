# $NetBSD: Makefile,v 1.3 2020/12/21 11:17:36 mef Exp $

R_PKGNAME=	openssl
R_PKGVER=	1.4.3
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Toolkit for encryption, signatures and certificates based on OpenSSL
LICENSE=	mit

DEPENDS+=	R-askpass>=1.1:../../security/R-askpass

# Packages suggested but not available:
#  'jose', 'sodium'

TEST_DEPENDS+=-R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=-R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=-R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown


USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
