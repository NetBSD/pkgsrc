# $NetBSD: Makefile,v 1.5 2024/01/21 04:49:57 mef Exp $

R_PKGNAME=	data.table
R_PKGVER=	1.14.10
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Extension of 'data.frame'
LICENSE=	mpl-2.0

# Packages suggested but not available:
#  'nanotime'

TEST_DEPENDS+=	R-bit64-[0-9]*:../../devel/R-bit64
TEST_DEPENDS+=	R-bit-[0-9]*:../../devel/R-bit
TEST_DEPENDS+=	R-curl-[0-9]*:../../www/R-curl
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-R.utils-[0-9]*:../../devel/R-R.utils
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-xts-[0-9]*:../../math/R-xts
TEST_DEPENDS+=	R-yaml-[0-9]*:../../textproc/R-yaml
TEST_DEPENDS+=	R-zoo-[0-9]*:../../math/R-zoo

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
