# $NetBSD: Makefile,v 1.1 2022/08/24 10:16:52 wiz Exp $

DISTNAME=	coveralls-3.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/coveralls/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://github.com/z4r/python-coveralls
COMMENT=	Python interface to coveralls.io API
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-coverage>=4.1:../../devel/py-coverage
DEPENDS+=	${PYPKGPREFIX}-docopt>=0.6.1:../../devel/py-docopt
DEPENDS+=	${PYPKGPREFIX}-requests>=1.0.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.10:../../textproc/py-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=0:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-responses>=0:../../net/py-responses
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=0:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
