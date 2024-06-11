# $NetBSD: Makefile,v 1.9 2024/06/11 09:19:30 adam Exp $

DISTNAME=	requests_ntlm-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	security www python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/requests_ntlm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/requests/requests-ntlm
COMMENT=	NTLM authentication handler for python-requests
LICENSE=	isc

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-pyspnego>=0.4.0:../../security/py-pyspnego
DEPENDS+=	${PYPKGPREFIX}-requests>=2.0.0:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
PYTHON_VERSIONED_DEPENDENCIES+=	cryptography
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
