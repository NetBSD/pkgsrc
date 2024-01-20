# $NetBSD: Makefile,v 1.1 2024/01/20 02:10:16 mef Exp $

R_PKGNAME=	debugme
R_PKGVER=	1.1.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Debug R Packages
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-crayon>=1.5.2:../../devel/R-crayon

# !pdfTeX error: pdflatex (file tctt1000): Font tctt1000 at 600 not found

TEST_DEPENDS+=	R-mockery-[0-9]*:../../devel/R-mockery
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
