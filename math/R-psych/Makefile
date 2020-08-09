# $NetBSD: Makefile,v 1.2 2020/08/09 16:45:23 brook Exp $

R_PKGNAME=	psych
R_PKGVER=	1.9.12.31

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/psych/
COMMENT=	Procedures for psychological and psychometric research
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-mnormt>=1.5.4:../../math/R-mnormt

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
