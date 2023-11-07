# $NetBSD: Makefile,v 1.7 2023/11/07 22:38:00 wiz Exp $

DISTNAME=	requests-unixsocket-0.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/requests-unixsocket/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/msabramo/requests-unixsocket
COMMENT=	Use requests to talk HTTP via a UNIX domain socket
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-pbr-[0-9]*:../../devel/py-pbr
DEPENDS+=	${PYPKGPREFIX}-requests>=1.1:../../devel/py-requests

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	requests_unixsocket/tests/test_requests_unixsocket.py

do-test:
	${DO_NADA}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
