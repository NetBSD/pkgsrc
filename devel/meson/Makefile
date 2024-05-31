# $NetBSD: Makefile,v 1.66 2024/05/31 04:22:41 adam Exp $

DISTNAME=	meson-1.4.1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/meson/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mesonbuild.com/
COMMENT=	Open source build system meant to be fast and user friendly
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	ninja-build>=1.7:../../devel/ninja-build

CONFLICTS+=	py[0-9]*-meson-[0-9]*
SUPERSEDES+=	py[0-9]*-meson-[0-9]*

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	c c++ # c++ for tests
# XXX only needed for tests, but itstool:test didn't work
USE_TOOLS+=	itstool

SUBST_CLASSES+=		man
SUBST_SED.man+=		-e "s,share/man,${PKGMANDIR},"
SUBST_FILES.man+=	setup.py
SUBST_STAGE.man=	pre-configure
SUBST_MESSAGE.man=	Fixing man page installation path.

REPLACE_PYTHON+=	meson.py
REPLACE_PYTHON+=	mesonbuild/rewriter.py
REPLACE_PYTHON+=	run_*.py
REPLACE_PYTHON+=	test\ cases/*/*/*.py
REPLACE_PYTHON+=	test\ cases/*/*/*/*.py
REPLACE_PYTHON+=	test\ cases/*/*/*/*/*.py
REPLACE_PYTHON+=	test\ cases/common/14\ configure\ file/test.py.in
REPLACE_PYTHON+=	test\ cases/windows/8\ find\ program/test-script
REPLACE_PYTHON+=	tools/*.py

# Total passed tests:  489
# Total failed tests:  90
# Total skipped tests: 169
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} run_tests.py

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
# the following are only for tests
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
