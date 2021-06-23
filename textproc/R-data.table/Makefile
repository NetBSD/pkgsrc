# $NetBSD: Makefile,v 1.4 2021/06/23 19:59:11 bacon Exp $

R_PKGNAME=	data.table
R_PKGVER=	1.14.0
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Extension of 'data.frame'
LICENSE=	mpl-2.0

TEST_DEPENDS+=	R-bit64-[0-9]*:../../devel/R-bit64
TEST_DEPENDS+=	R-bit-[0-9]*:../../devel/R-bit
TEST_DEPENDS+=	R-xts-[0-9]*:../../math/R-xts
TEST_DEPENDS+=	R-zoo-[0-9]*:../../math/R-zoo

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
