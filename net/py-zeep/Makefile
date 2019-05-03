# $NetBSD: Makefile,v 1.9 2019/05/03 10:54:38 adam Exp $

DISTNAME=	zeep-3.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zeep/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://docs.python-zeep.org/
COMMENT=	Fast and modern Python SOAP client
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-appdirs>=1.4.0:../../devel/py-appdirs
DEPENDS+=	${PYPKGPREFIX}-attrs>=17.2.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-cached-property>=1.3.0:../../devel/py-cached-property
DEPENDS+=	${PYPKGPREFIX}-defusedxml>=0.4.1:../../textproc/py-defusedxml
DEPENDS+=	${PYPKGPREFIX}-isodate>=0.5.4:../../time/py-isodate
DEPENDS+=	${PYPKGPREFIX}-lxml>=3.1.0:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-requests>=2.7.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-requests-toolbelt>=0.7.1:../../devel/py-requests-toolbelt
DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six
#TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun>=0.3.8:../../devel/py-freezegun
#TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=2.0.0:../../devel/py-mock
#TEST_DEPENDS+=	${PYPKGPREFIX}-pretend>=1.0.8:../../devel/py-pretend
#TEST_DEPENDS+=	${PYPKGPREFIX}-requests-mock>=0.7.0:../../devel/py-requests-mock
#TEST_DEPENDS+=	${PYPKGPREFIX}-test>=3.1.3:../../devel/py-test
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.5.1:../../devel/py-test-cov
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
# TEST_DEPENDS not packaged: pytest-tornado, aioresponses

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} != 27
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=1.0:../../www/py-aiohttp
.endif

USE_LANGUAGES=	# none

PYSETUPTESTTARGET=	pytest

# tests are not compatible with the latest py-test
do-test:
	${DO_NADA}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
