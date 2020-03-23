# $NetBSD: Makefile,v 1.2 2020/03/23 10:21:41 tnn Exp $

DISTNAME=	requests-unixsocket-0.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/requests-unixsocket/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/msabramo/requests-unixsocket
COMMENT=	Use requests to talk HTTP via a UNIX domain socket
LICENSE=	apache-2.0

BUILD_DEPENDS+=	${PYPKGPREFIX}-pbr-[0-9]*:../../devel/py-pbr
DEPENDS+=	${PYPKGPREFIX}-requests>=1.1:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.8:../../www/py-urllib3

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	requests_unixsocket/tests/test_requests_unixsocket.py

do-test:
	${DO_NADA}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
