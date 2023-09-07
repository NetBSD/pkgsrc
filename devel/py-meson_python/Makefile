# $NetBSD: Makefile,v 1.3 2023/09/07 15:40:41 adam Exp $

DISTNAME=	meson_python-0.14.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/meson_python/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mesonbuild/meson-python
COMMENT=	Meson Python build backend (PEP 517)
LICENSE=	mit

DEPENDS+=	meson>=0.63.3:../../devel/meson
DEPENDS+=	${PYPKGPREFIX}-project-metadata>=0.7.1:../../devel/py-project-metadata
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=6.0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
TEST_DEPENDS+=	git-base-[0-9]*:../../devel/git-base

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli>=1.0.0:../../textproc/py-tomli
.endif
.if ${PYTHON_VERSION} >= 312
DEPENDS+=	${PYPKGPREFIX}-setuptools>=60.0:../../devel/py-setuptools
.endif

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
