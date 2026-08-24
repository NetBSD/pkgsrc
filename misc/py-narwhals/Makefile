# $NetBSD: Makefile,v 1.3 2026/08/24 12:38:27 adam Exp $

DISTNAME=	narwhals-2.25.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/narwhals/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/narwhals-dev/narwhals
COMMENT=	Extremely lightweight compatibility layer between dataframe libraries
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-uv-build>=0.11.0:../../devel/py-uv-build
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=6.0.0:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-pandas>=1.3.4:../../math/py-pandas
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-env>=0:../../devel/py-test-env
TEST_DEPENDS+=	${PYPKGPREFIX}-test-randomly>=0:../../devel/py-test-randomly
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=0:../../devel/py-test-xdist

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
