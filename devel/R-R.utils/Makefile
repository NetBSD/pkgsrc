# $NetBSD: Makefile,v 1.6 2024/01/20 03:27:16 mef Exp $

R_PKGNAME=	R.utils
R_PKGVER=	2.12.3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Various Programming Utilities
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	R-R.methodsS3-[0-9]*:../../devel/R-R.methodsS3
DEPENDS+=	R-R.oo-[0-9]*:../../devel/R-R.oo

# !pdfTeX error: pdflatex (file tctt0900): Font tctt0900 at 600 not found

TEST_DEPENDS+=	R-R.oo-[0-9]*:../../devel/R-R.oo
TEST_DEPENDS+=	R-R.methodsS3-[0-9]*:../../devel/R-R.methodsS3
TEST_DEPENDS+=	R-digest-[0-9]*:../../security/R-digest
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
