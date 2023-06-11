# $NetBSD: Makefile,v 1.5 2023/06/11 00:44:59 mef Exp $

R_PKGNAME=	psych
R_PKGVER=	2.3.3

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/psych/
COMMENT=	Procedures for psychological and psychometric research
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-mnormt>=1.5.4:../../math/R-mnormt
#Packages suggested but not available:
#  'psychTools', 'GPArotation', 'lavaan', 'Rcsdp'
#TEST_DEPENDS+=	R-graph-[0-9]*:../../math/R-graph
#EST_DEPENDS+=	R-psychTools-[0-9]*:
#EST_DEPENDS+=	R-GPArotation-[0-9]*:
#EST_DEPENDS+=	R-lavaan-[0-9]*:
#EST_DEPENDS+=	R-Rcsdp-[0-9]*:
#EST_DEPENDS+=	R-graph-[0-9]*:../../wip/R-graph
#EST_DEPENDS+=	R-Rgraphviz-[0-9]*:../../wip/R-Rgraphviz


.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
