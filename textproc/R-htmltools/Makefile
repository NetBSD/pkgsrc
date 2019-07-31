# $NetBSD: Makefile,v 1.2 2019/07/31 20:52:24 brook Exp $

CATEGORIES=	textproc R

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rstudio/htmltools
COMMENT=	Tools for HTML
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

R_PKGNAME=	htmltools
R_PKGVER=	0.3.6

DEPENDS+=	R-digest>=0.6.20:../../security/R-digest

USE_LANGUAGES+=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
