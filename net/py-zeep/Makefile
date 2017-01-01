# $NetBSD: Makefile,v 1.3 2017/01/01 14:43:53 wiz Exp $

DISTNAME=	zeep-0.23.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zeep/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://docs.python-zeep.org/
COMMENT=	Fast and modern Python SOAP client
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-requests>=2.7.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-lxml>=3.0.0:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-isodate>=0.5.1:../../time/py-isodate
DEPENDS+=	${PYPKGPREFIX}-defusedxml>=0.4.1:../../textproc/py-defusedxml
DEPENDS+=	${PYPKGPREFIX}-cached-property>=1.0.0:../../devel/py-cached-property
DEPENDS+=	${PYPKGPREFIX}-appdirs>=1.4.0:../../devel/py-appdirs

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36	# devel/py-cached-property

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
