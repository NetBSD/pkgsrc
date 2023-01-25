# $NetBSD: Makefile,v 1.1 2023/01/25 09:17:36 adam Exp $

DISTNAME=	kubernetes-25.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=k/kubernetes/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kubernetes-client/python
COMMENT=	Kubernetes Python client
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-certifi>=14.05.14:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.5.3:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-google-auth>=1.0.1:../../security/py-google-auth
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-requests-oauthlib-[0-9]*:../../security/py-requests-oauthlib
DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.24.2:../../www/py-urllib3
DEPENDS+=	${PYPKGPREFIX}-websocket-client>=0.43.0:../../www/py-websocket-client
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.4.1:../../textproc/py-yaml

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
