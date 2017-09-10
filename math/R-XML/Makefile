# $NetBSD: Makefile,v 1.7 2017/09/10 15:41:18 alnsn Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/XML/
COMMENT=	Tools for parsing and generating XML within R
LICENSE=	2-clause-bsd

R_PKGNAME=	XML
R_PKGVER=	3.98-1.6

.include "../../math/R/Makefile.extension"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
