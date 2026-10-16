# $NetBSD: Makefile,v 1.36 2026/10/16 17:46:08 adam Exp $

DISTNAME=	pydoctor-25.10.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pydoctor/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/twisted/pydoctor
COMMENT=	Python API document generator
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-attrs>=0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-configargparse>=0:../../devel/py-configargparse
DEPENDS+=	${PYPKGPREFIX}-cachecontrol>=0.12.14:../../devel/py-cachecontrol
DEPENDS+=	${PYPKGPREFIX}-docutils>=0.17:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-lunr>=0.6.2:../../textproc/py-lunr
DEPENDS+=	${PYPKGPREFIX}-platformdirs>=0:../../misc/py-platformdirs
DEPENDS+=	${PYPKGPREFIX}-requests>=0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-twisted>=0:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-urllib3>=2.0:../../www/py-urllib3
TEST_DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=0:../../www/py-beautifulsoup4
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=0:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-sphinx>=0:../../textproc/py-sphinx
TEST_DEPENDS+=	${PYPKGPREFIX}-test-subtests>=0:../../devel/py-test-subtests

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	pydoctor

PYTHON_VERSIONS_INCOMPATIBLE=	311 # py-sphinx

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
