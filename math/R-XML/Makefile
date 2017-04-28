# $NetBSD: Makefile,v 1.6 2017/04/28 17:25:10 alnsn Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	alnsn@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/XML/
COMMENT=	Tools for parsing and generating XML within R
LICENSE=	2-clause-bsd

R_PKGNAME=	XML
R_PKGVER=	3.98-1.6

.include "../../math/R/Makefile.extension"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
