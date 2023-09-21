# $NetBSD: Makefile,v 1.56 2023/09/21 01:44:06 gutteridge Exp $

DISTNAME=	meson-1.2.1
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/meson/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mesonbuild.com/
COMMENT=	Open source build system meant to be fast and user friendly
LICENSE=	apache-2.0

CONFLICTS=	${PYPKGPREFIX}-meson-[0-9]*
SUPERSEDES=	${PYPKGPREFIX}-meson-[0-9]*

DEPENDS+=	ninja-build>=1.7:../../devel/ninja-build

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

USE_LANGUAGES=	c c++ # c++ for tests

SUBST_CLASSES+=		man
SUBST_SED.man+=		-e "s,share/man,${PKGMANDIR},"
SUBST_FILES.man+=	setup.py
SUBST_STAGE.man=	pre-configure
SUBST_MESSAGE.man=	Fixing man page installation path.

# XXX this isn't an entirely correct approach, as this package is not
# Python-versioned, while py-cython is. This means in bulk builds, any
# Python packages that use meson and cython will fail with a mismatch
# for non-default Python versions, e.g., py-pandas and py-scipy.
SUBST_CLASSES+=		cython
SUBST_STAGE.cython=	pre-configure
SUBST_MESSAGE.cython=	Fixing cython binary name.
SUBST_FILES.cython=	mesonbuild/compilers/detect.py
SUBST_SED.cython=	-e "s,'cython3','cython-${PYVERSSUFFIX}',"

REPLACE_PYTHON+=	ghwt.py
REPLACE_PYTHON+=	meson.py
REPLACE_PYTHON+=	mesonbuild/rewriter.py
REPLACE_PYTHON+=	mesonbuild/cmake/data/run_ctgt.py
REPLACE_PYTHON+=	run_*.py
REPLACE_PYTHON+=	test\ cases/*/*/*.py
REPLACE_PYTHON+=	test\ cases/*/*/*/*.py
REPLACE_PYTHON+=	test\ cases/*/*/*/*/*.py
REPLACE_PYTHON+=	test\ cases/common/14\ configure\ file/test.py.in
REPLACE_PYTHON+=	test\ cases/common/187\ find\ override/subdir/gencodegen.py.in
REPLACE_PYTHON+=	test\ cases/common/54\ run\ target/configure.in
REPLACE_PYTHON+=	test\ cases/windows/8\ find\ program/test-script
REPLACE_PYTHON+=	tools/*.py

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} run_tests.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
