# $NetBSD: Makefile,v 1.1 2011/06/14 21:30:08 alnsn Exp $

CATEGORIES=		math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=		alnsn@NetBSD.org
HOMEPAGE=		${R_HOMEPAGE_BASE}/XML/
COMMENT=		Tools for parsing and generating XML within R
LICENSE=		2-clause-bsd

R_PKGNAME=		XML
R_PKGVER=		3.4-0

.include "../../math/R/Makefile.extension"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
