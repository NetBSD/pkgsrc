# $NetBSD: Makefile,v 1.1 2016/02/25 19:43:57 fhajny Exp $

CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/gsubfn/
COMMENT=	R package used for string matching, substitution and parsing
LICENSE=	gnu-gpl-v2

R_PKGNAME=	gsubfn
R_PKGVER=	0.6-6

DEPENDS+=	R-proto-[0-9]*:../../devel/R-proto

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
