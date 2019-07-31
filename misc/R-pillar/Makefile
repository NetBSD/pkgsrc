# $NetBSD: Makefile,v 1.4 2019/07/31 20:42:03 brook Exp $

CATEGORIES=	misc R

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/r-lib/pillar
COMMENT=	Coloured formatting for columns
LICENSE=	gnu-gpl-v3

R_PKGNAME=	pillar
R_PKGVER=	1.4.2

DEPENDS+=	R-cli>=1.1.0:../../devel/R-cli
DEPENDS+=	R-crayon>=1.3.4:../../devel/R-crayon
DEPENDS+=	R-fansi>=0.4.0:../../devel/R-fansi
DEPENDS+=	R-rlang>=0.3.0:../../devel/R-rlang
DEPENDS+=	R-vctrs>=0.2.0:../../math/R-vctrs
DEPENDS+=	R-utf8>=1.1.0:../../textproc/R-utf8
DEPENDS+=	R-utf8>=1.1.3:../../textproc/R-utf8

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
