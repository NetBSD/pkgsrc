# $NetBSD: Makefile,v 1.7 2021/06/05 08:33:02 mef Exp $

R_PKGNAME=	highr
R_PKGVER=	0.9
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Syntax highlighting for R source code
LICENSE=	gnu-gpl-v1 OR gnu-gpl-v2 OR gnu-gpl-v3

TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-markdown-[0-9]*:../../textproc/R-markdown

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
