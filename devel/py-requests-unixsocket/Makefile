# $NetBSD: Makefile,v 1.10 2025/03/15 20:37:10 adam Exp $

DISTNAME=	requests_unixsocket-0.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/requests-unixsocket/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/msabramo/requests-unixsocket
COMMENT=	Use requests to talk HTTP via a UNIX domain socket
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=64:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=8:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-requests>=1.1:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-waitress-[0-9]*:../../www/py-waitress

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	requests_unixsocket/tests/test_requests_unixsocket.py

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
