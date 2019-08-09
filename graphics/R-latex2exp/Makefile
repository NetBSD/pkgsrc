# $NetBSD: Makefile,v 1.1 2019/08/09 15:20:31 brook Exp $

R_PKGNAME=	latex2exp
R_PKGVER=	0.4.0
CATEGORIES=	graphics textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Use LaTeX expressions in plots
LICENSE=	mit

DEPENDS+=	R-magrittr>=1.5:../../devel/R-magrittr
DEPENDS+=	R-stringr>=1.4.0:../../textproc/R-stringr

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
