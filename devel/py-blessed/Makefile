# $NetBSD: Makefile,v 1.21 2026/09/08 05:48:39 adam Exp $

DISTNAME=	blessed-1.49.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/blessed/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jquast/blessed
COMMENT=	Wrapper around terminal styling, screen positioning, and input
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-jinxed>=2.1:../../devel/py-jinxed
DEPENDS+=	${PYPKGPREFIX}-wcwidth>=0.8.3:../../devel/py-wcwidth
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov

USE_LANGUAGES=	# none

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
