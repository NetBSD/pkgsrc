# $NetBSD: Makefile,v 1.93 2026/04/21 04:45:10 adam Exp $
#
# Release notes in markdown format:
# https://github.com/mesonbuild/meson/tree/master/docs/markdown/

DISTNAME=	meson-1.11.1
CATEGORIES=	devel python
#MASTER_SITES=	${MASTER_SITE_PYPI:=m/meson/}
MASTER_SITES=	${MASTER_SITE_GITHUB:=mesonbuild/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mesonbuild.com/
COMMENT=	Open source build system meant to be fast and user friendly
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	ninja-build>=1.7:../../devel/ninja-build
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=0:../../devel/py-test

CONFLICTS+=	py[0-9]*-meson-[0-9]*
SUPERSEDES+=	py[0-9]*-meson-[0-9]*

USE_LANGUAGES=	c c++ # c++ for tests
USE_TOOLS+=	itstool:test pkg-config

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

# as of 1.11.0
# Total passed tests:  503
# Total failed tests:  13
# Total skipped tests: 113

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} run_tests.py

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
# the following are only for tests
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
