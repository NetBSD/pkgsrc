# $NetBSD: Makefile,v 1.6 2026/06/01 10:24:41 wiz Exp $

DISTNAME=	pytest_socket-0.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest_socket/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/miketheman/pytest-socket
COMMENT=	Pytest Plugin to disable socket calls during tests
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-uv-build>=0:../../devel/py-uv-build
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
