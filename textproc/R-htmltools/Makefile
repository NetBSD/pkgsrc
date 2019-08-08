# $NetBSD: Makefile,v 1.3 2019/08/08 19:53:57 brook Exp $

R_PKGNAME=	htmltools
R_PKGVER=	0.3.6
CATEGORIES=	textproc

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Tools for HTML
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-digest>=0.6.20:../../security/R-digest

USE_LANGUAGES+=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
