# $NetBSD: Makefile,v 1.2 2024/10/19 06:02:59 mef Exp $

DISTNAME=	RUnit_0.4.33
CATEGORIES=	devel
MASTER_SITES=	https://cran.rstudio.com/src/contrib/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cran.rstudio.com/web/packages/RUnit/index.html
COMMENT=	R functions implementing a standard Unit Testing framework

LICENSE=	gnu-gpl-v2

TEST_DEPENDS+=	R-XML-[0-9]*:../../math/R-XML

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
