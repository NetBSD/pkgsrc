# $NetBSD: Makefile,v 1.5 2019/08/08 19:53:55 brook Exp $

R_PKGNAME=	pillar
R_PKGVER=	1.4.2
CATEGORIES=	misc

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Coloured formatting for columns
LICENSE=	gnu-gpl-v3

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
