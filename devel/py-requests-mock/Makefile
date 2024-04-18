# $NetBSD: Makefile,v 1.22 2024/04/18 07:13:20 adam Exp $

DISTNAME=	requests-mock-1.12.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel www python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/requests-mock/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://requests-mock.readthedocs.org/
COMMENT=	Mock out responses from the requests package
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=56:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-requests>=2.22:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-fixtures-[0-9]*:../../devel/py-fixtures
TEST_DEPENDS+=	${PYPKGPREFIX}-purl-[0-9]*:../../www/py-purl
TEST_DEPENDS+=	${PYPKGPREFIX}-requests-futures-[0-9]*:../../devel/py-requests-futures
TEST_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
TEST_DEPENDS+=	${PYPKGPREFIX}-testtools-[0-9]*:../../devel/py-testtools
TEST_DEPENDS+=	${PYPKGPREFIX}-testrepository>=0.0.18:../../devel/py-testrepository

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
