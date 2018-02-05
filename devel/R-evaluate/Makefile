# $NetBSD: Makefile,v 1.5 2018/02/05 19:01:54 minskim Exp $

CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/evaluate/
COMMENT=	Parsing and evaluation tools
# TODO: LICENSE=	GPL

R_PKGNAME=	evaluate
R_PKGVER=	0.10.1

DEPENDS+=	R-stringr>=0.6.2:../../textproc/R-stringr

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
