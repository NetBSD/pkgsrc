# $NetBSD: Makefile,v 1.7 2024/10/22 11:06:20 adam Exp $

DISTNAME=	meson_python-0.17.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/meson_python/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mesonbuild/meson-python
COMMENT=	Meson Python build backend (PEP 517)
LICENSE=	mit

DEPENDS+=	meson>=1.2.3:../../devel/meson
DEPENDS+=	${PYPKGPREFIX}-packaging>=19.0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-project-metadata>=0.7.1:../../devel/py-project-metadata
TEST_DEPENDS+=	${PYPKGPREFIX}-cython>=3.0.3:../../devel/py-cython
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
TEST_DEPENDS+=	git-base-[0-9]*:../../devel/git-base

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli>=1.0.0:../../textproc/py-tomli
.endif

SUBST_CLASSES+=		cython
SUBST_STAGE.cython=	pre-configure
SUBST_MESSAGE.cython=	Fixing path to cython.
SUBST_FILES.cython=	tests/test_editable.py
SUBST_SED.cython=	-e "s,'cython','cython-${PYVERSSUFFIX}',"

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
