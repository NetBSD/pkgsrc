# $NetBSD: Makefile,v 1.3 2023/11/27 15:31:19 adam Exp $

DISTNAME=	loguru-0.7.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/loguru/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Delgan/loguru
COMMENT=	Python logging made (stupidly) simple
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun>=1.2.2:../../devel/py-freezegun
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4.0.0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mypy-plugins>=1.10.1:../../devel/py-test-mypy-plugins

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
