# $NetBSD: Makefile,v 1.3 2024/10/18 15:24:49 mef Exp $

R_PKGNAME=	globals
R_PKGVER=	0.16.3

CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Identify Global Objects in R Expressions
LICENSE=	gnu-lgpl-v2.1 OR gnu-lgpl-v3

USE_LANGUAGES=	# none

TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
#EST_DEPENDS+=	tex-texlive-scripts-[0-9]*:../../print/tex-texlive-scripts

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
