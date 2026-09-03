# $NetBSD: Makefile,v 1.7 2026/09/03 09:00:25 adam Exp $

DISTNAME=	pytest_socket-0.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest_socket/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/miketheman/pytest-socket
COMMENT=	Pytest Plugin to disable socket calls during tests
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-uv-build>=0.7.20:../../devel/py-uv-build
DEPENDS+=	${PYPKGPREFIX}-test>=7.0.0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-randomly>=3.15.0:../../devel/py-test-randomly

USE_LANGUAGES=	# none

# as of 0.8.0
# 2 failed, 84 passed

.if make(test)
ALLOW_NETWORK_ACCESS=	yes
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
