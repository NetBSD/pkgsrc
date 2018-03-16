# $NetBSD: Makefile,v 1.1 2018/03/16 16:19:05 minskim Exp $

CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/r-lib/pillar
COMMENT=	Colored formatting for columns
LICENSE=	gnu-gpl-v3

R_PKGNAME=	pillar
R_PKGVER=	1.1.0

DEPENDS+=	R-cli-[0-9]*:../../devel/R-cli
DEPENDS+=	R-crayon>=1.3.4:../../devel/R-crayon
DEPENDS+=	R-rlang-[0-9]*:../../devel/R-rlang
DEPENDS+=	R-utf8>=1.1.3:../../textproc/R-utf8

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.R+=	R>=2.10
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
