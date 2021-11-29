# $NetBSD: Makefile,v 1.3 2021/11/29 10:47:58 mef Exp $

R_PKGNAME=	diffobj
R_PKGVER=	0.3.5
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Diffs for R Objects
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-crayon>=1.3.2:../../devel/R-crayon

TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
