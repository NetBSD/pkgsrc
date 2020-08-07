# $NetBSD: Makefile,v 1.1 2020/08/07 02:46:40 brook Exp $

MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/psych/
COMMENT=	Procedures for psychological and psychometric research
LICENSE=	gnu-gpl-v2

R_PKGNAME=	psych
R_PKGVER=	1.9.12.31

DEPENDS+=	R-mnormt>=1.5.4:../../math/R-mnormt

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
