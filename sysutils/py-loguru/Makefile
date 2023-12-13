# $NetBSD: Makefile,v 1.4 2023/12/13 19:22:45 wiz Exp $

DISTNAME=	loguru-0.7.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/loguru/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Delgan/loguru
COMMENT=	Python logging made (stupidly) simple
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun>=1.2.2:../../devel/py-freezegun
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4.0.0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mypy-plugins>=1.10.1:../../devel/py-test-mypy-plugins

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
