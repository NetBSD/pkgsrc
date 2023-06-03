# $NetBSD: Makefile,v 1.9 2023/06/03 13:58:21 mef Exp $

R_PKGNAME=	highr
R_PKGVER=	0.10
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Syntax highlighting for R source code
LICENSE=	gnu-gpl-v1 OR gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-xfun-[0-9]*:../../devel/R-xfun

TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-markdown-[0-9]*:../../textproc/R-markdown

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
