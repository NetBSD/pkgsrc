# $NetBSD: Makefile,v 1.8 2023/08/03 08:23:31 adam Exp $

DISTNAME=	requests_ntlm-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	security www python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/requests_ntlm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/requests/requests-ntlm
COMMENT=	NTLM authentication handler for python-requests
LICENSE=	isc

DEPENDS+=	${PYPKGPREFIX}-pyspnego>=0.1.6:../../security/py-pyspnego
DEPENDS+=	${PYPKGPREFIX}-requests>=2.0.0:../../devel/py-requests

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
PYTHON_VERSIONED_DEPENDENCIES+=	cryptography
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
