# $NetBSD: Makefile,v 1.7 2019/03/13 18:02:31 adam Exp $

DISTNAME=	zeep-3.1.0
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
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun>=0.3.8:../../devel/py-freezegun
#mock==2.0.0
#pretend==1.0.8
#pytest-cov==2.5.1
#pytest==3.1.3
#requests_mock>=0.7.0
#pytest-tornado==0.4.5
#isort==4.2.15
#flake8==3.3.0
#flake8-blind-except==0.1.1
#flake8-debugger==1.4.0
#flake8-imports==0.1.1
#aioresponses>=0.4.1

.include "../../lang/python/pyversion.mk"
PLIST_VARS+=	aio
.if "${PYPKGPREFIX}" != "py27" && "${PYPKGPREFIX}" != "py34"
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=1.0:../../www/py-aiohttp
PLIST.aio=	yes
.endif

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
