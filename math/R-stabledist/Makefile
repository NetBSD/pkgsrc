# $NetBSD: Makefile,v 1.5 2024/11/24 01:57:53 mef Exp $

R_PKGNAME=	stabledist
R_PKGVER=	0.7-2

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Stable distribution functions
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

# Packages suggested but not available:
#   'FMStable', 'Rmpfr', 'sfsmisc', 'libstable4u'

TEST_DEPENDS+=	R-fBasics-[0-9]*:../../finance/R-fBasics
TEST_DEPENDS+=	R-RUnit-[0-9]*:../../devel/R-RUnit

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
