# $NetBSD: Makefile,v 1.14 2026/09/28 15:41:50 wiz Exp $

DISTNAME=	meson_python-0.22.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/meson_python/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mesonbuild/meson-python
COMMENT=	Meson Python build backend (PEP 517)
LICENSE=	mit

DEPENDS+=	meson>=1.2.3:../../devel/meson
DEPENDS+=	${PYPKGPREFIX}-packaging>=24.2:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-project-metadata>=0.9.0:../../devel/py-project-metadata
TEST_DEPENDS+=	${PYPKGPREFIX}-cython>=3.0.3:../../devel/py-cython
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=0:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
TEST_DEPENDS+=	patchelf-[0-9]*:../../devel/patchelf

USE_TOOLS+=	git:test

# as of 0.22.0
# 22 failed, 123 passed, 14 skipped, 9 errors

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
