# $NetBSD: Makefile,v 1.3 2018/07/28 14:40:51 brook Exp $

CATEGORIES=	misc

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/r-lib/pillar
COMMENT=	Coloured Formatting for Columns
LICENSE=	gnu-gpl-v3

R_PKGNAME=	pillar
R_PKGVER=	1.2.1

DEPENDS+=	R-cli>=1.0.0:../../devel/R-cli
DEPENDS+=	R-crayon>=1.3.4:../../devel/R-crayon
DEPENDS+=	R-rlang>=0.2.0:../../devel/R-rlang
DEPENDS+=	R-utf8>=1.1.3:../../textproc/R-utf8

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
