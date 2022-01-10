# $NetBSD: Makefile,v 1.2 2022/01/10 22:00:08 wiz Exp $

DISTNAME=	pydyf-0.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	print python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pydyf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.courtbouillon.org/pydyf
COMMENT=	Low-level PDF generator
LICENSE=	modified-bsd

TEST_DEPENDS+=	ghostscript-agpl-[0-9]*:../../print/ghostscript-agpl
TEST_DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-flake8-[0-9]*:../../devel/py-test-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-test-isort-[0-9]*:../../devel/py-test-isort

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
