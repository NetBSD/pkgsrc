# $NetBSD: Makefile,v 1.7 2024/11/12 14:28:44 mef Exp $

R_PKGNAME=	psych
R_PKGVER=	2.4.6.26

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/psych/
COMMENT=	Procedures for psychological and psychometric research
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-mnormt>=1.5.4:../../math/R-mnormt
DEPENDS+=	R-GPArotation-[0-9]*:../../math/R-GPArotation

# Packages suggested but not available:
#   'psychTools', 'lavaan', 'Rcsdp', 'graph', 'Rgraphviz'

TEST_DEPENDS+=	R-lme4-[0-9]*:../../math/R-lme4
#EST_DEPENDS+=	R-graph-[0-9]*:../../wip/R-graph
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
#EST_DEPENDS+=	R-Rgraphviz-[0-9]*:../../wip/R-Rgraphviz


.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
