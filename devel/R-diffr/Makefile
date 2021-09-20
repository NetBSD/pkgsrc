# $NetBSD: Makefile,v 1.1 2021/09/20 03:06:37 mef Exp $

R_PKGNAME=	diffr
R_PKGVER=	0.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Display Differences Between Two Files using Codediff Library
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-htmlwidgets>=1.5.4:../../www/R-htmlwidgets
TEST_DEPENDS+=	R-shiny-[0-9]*:../../www/R-shiny

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
