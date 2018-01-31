# $NetBSD: Makefile,v 1.6 2018/01/31 11:37:29 adam Exp $

DISTNAME=	zeep-2.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zeep/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://docs.python-zeep.org/
COMMENT=	Fast and modern Python SOAP client
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-appdirs>=1.4.0:../../devel/py-appdirs
DEPENDS+=	${PYPKGPREFIX}-defusedxml>=0.4.1:../../textproc/py-defusedxml
DEPENDS+=	${PYPKGPREFIX}-cached-property>=1.0.0:../../devel/py-cached-property
DEPENDS+=	${PYPKGPREFIX}-isodate>=0.5.4:../../time/py-isodate
DEPENDS+=	${PYPKGPREFIX}-lxml>=3.0.0:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-requests>=2.7.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-requests-toolbelt>=0.7.1:../../devel/py-requests-toolbelt
DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz

.include "../../lang/python/pyversion.mk"

PLIST_VARS+=	aio
.if "${PYPKGPREFIX}" != "py27" && "${PYPKGPREFIX}" != "py34"
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=1.0:../../www/py-aiohttp
PLIST.aio=	yes
.endif

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
