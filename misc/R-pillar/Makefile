# $NetBSD: Makefile,v 1.2 2018/04/07 21:06:34 minskim Exp $

CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

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
