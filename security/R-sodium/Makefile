# $NetBSD: Makefile,v 1.2 2023/02/19 11:51:05 mef Exp $

R_PKGNAME=	sodium
R_PKGVER=	1.2.1
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Modern and Easy-to-Use Crypto Library
LICENSE=	mit	# + file LICENSE

TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown

USE_LANGUAGES=	c

.include "../../security/libsodium/buildlink3.mk"
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
