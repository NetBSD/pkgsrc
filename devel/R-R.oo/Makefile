# $NetBSD: Makefile,v 1.4 2024/02/06 12:10:19 mef Exp $

R_PKGNAME=	R.oo
R_PKGVER=	1.26.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	R Object-Oriented Programming with or without References
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	R-R.methodsS3-[0-9]*:../../devel/R-R.methodsS3

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
