# $NetBSD: Makefile,v 1.20 2026/09/08 05:51:13 adam Exp $

DISTNAME=	kubernetes-36.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=k/kubernetes/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kubernetes-client/python
COMMENT=	Kubernetes Python client
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3.13.5:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-certifi>=14.05.14:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.5.3:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-durationpy>=0.7:../../time/py-durationpy
DEPENDS+=	${PYPKGPREFIX}-requests>=0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-requests-oauthlib>=0:../../security/py-requests-oauthlib
DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.24.2:../../www/py-urllib3
DEPENDS+=	${PYPKGPREFIX}-websocket-client>=0.43.0:../../www/py-websocket-client
DEPENDS+=	${PYPKGPREFIX}-yaml>=6.0.3:../../textproc/py-yaml
# google-auth
DEPENDS+=	${PYPKGPREFIX}-google-auth>=1.0.1:../../security/py-google-auth

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
