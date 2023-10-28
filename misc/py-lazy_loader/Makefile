# $NetBSD: Makefile,v 1.3 2023/10/28 19:57:12 wiz Exp $

DISTNAME=	lazy_loader-0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lazy_loader/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/scientific-python/lazy_loader
COMMENT=	Load subpackages and functions on demand
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.8:../../devel/py-flit_core
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=7.4:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4.1:../../devel/py-test-cov

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} lazy_loader

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
