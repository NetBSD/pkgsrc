# $NetBSD: Makefile,v 1.1 2018/05/12 21:54:24 minskim Exp $

DISTNAME=	htmltools_0.3.6
CATEGORIES=	textproc

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rstudio/htmltools
COMMENT=	Tools for HTML
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-digest-[0-9]*:../../security/R-digest

USE_LANGUAGES+=	c c++

BUILDLINK_API_DEPENDS.R+=	R>=2.14.1
.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
