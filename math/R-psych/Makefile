# $NetBSD: Makefile,v 1.3 2021/09/19 23:51:41 mef Exp $

R_PKGNAME=	psych
R_PKGVER=	2.1.6

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/psych/
COMMENT=	Procedures for psychological and psychometric research
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-mnormt>=1.5.4:../../math/R-mnormt
#Packages suggested but not available:
#  'psychTools', 'GPArotation', 'lavaan', 'Rcsdp', 'graph', 'Rgraphviz'
#TEST_DEPENDS+=	R-graph-[0-9]*:../../math/R-graph


.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
