# $NetBSD: Makefile,v 1.5 2024/01/26 12:31:53 mef Exp $

R_PKGNAME=	RcmdrMisc
R_PKGVER=	2.9-1

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	R Commander miscellaneous functions
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

USE_LANGUAGES=	# none

DEPENDS+=	R-colorspace>=1.4.1:../../graphics/R-colorspace
DEPENDS+=	R-abind>=1.4.5:../../math/R-abind
DEPENDS+=	R-car>=3.0.0:../../math/R-car
DEPENDS+=	R-e1071>=1.7.2:../../math/R-e1071
DEPENDS+=	R-nortest>=1.0.4:../../math/R-nortest
DEPENDS+=	R-sandwich>=2.5.1:../../math/R-sandwich
DEPENDS+=	R-Hmisc>=4.1.0:../../misc/R-Hmisc
DEPENDS+=	R-haven>=2.1.1:../../textproc/R-haven
DEPENDS+=	R-readstata13>=0.9.2:../../textproc/R-readstata13
DEPENDS+=	R-readxl>=1.3.1:../../textproc/R-readxl

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
