# $NetBSD: Makefile,v 1.1 2023/05/09 08:32:36 adam Exp $

DISTNAME=	lazy_loader-0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lazy_loader/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/scientific-python/lazy_loader
COMMENT=	Load subpackages and functions on demand
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.8:../../devel/py-flit_core
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=7.2:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4.0:../../devel/py-test-cov

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} lazy_loader

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
