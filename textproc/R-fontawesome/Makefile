# $NetBSD: Makefile,v 1.1 2022/04/30 01:38:19 mef Exp $

R_PKGNAME=	fontawesome
R_PKGVER=	0.2.2
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Easily Work with 'Font Awesome' Icons
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-rlang>=0.4.10:../../devel/R-rlang
DEPENDS+=	R-htmltools>=0.5.1.1:../../textproc/R-htmltools

TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
#EST_DEPENDS+=	R-rsvg-[0-9]*:

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
