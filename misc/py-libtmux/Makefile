# $NetBSD: Makefile,v 1.6 2026/11/26 22:44:02 kim Exp $

DISTNAME=	libtmux-0.68.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/libtmux/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://libtmux.git-pull.com/
COMMENT=	Typed Python API for tmux
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=0:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-rerunfailures>=0:../../devel/py-test-rerunfailures
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=0:../../devel/py-test-xdist

# as of 0.68.0
# 11 failed, 1376 passed, 62 skipped, 4 deselected, 22 rerun

USE_LANGUAGES=	# none

# Test the sources, not an installed copy that pytest would import first.
TEST_ENV+=	PYTHONPATH=${WRKSRC}/src

# Upstream's addopts and testpaths need gp-libs (doctests with its own
# option flags, README.md) and the docs tests need gp_sphinx and
# sphinx_ux_badges.  None are packaged, so run the unit tests only.
TEST_ADDOPTS=	--tb=short --no-header --reruns=2
TEST_ADDOPTS+=	--ignore=tests/test_docs_capabilities.py
# These hang in tmux load-buffer and source-file on NetBSD.
TEST_ADDOPTS+=	--deselect=tests/test_formats.py::test_buffer_paths
TEST_ADDOPTS+=	--deselect=tests/test_server.py::test_buffer_save_load
# --deselect matches by prefix, so this also drops test_source_file_quiet.
TEST_ADDOPTS+=	--deselect=tests/test_server.py::test_source_file
TEST_PATHS=	tests

# libtmux separates tmux format fields with a non-ASCII character, which
# tmux replaces with "_" unless the locale is UTF-8.  The locale has to
# come after TEST_ENV, which ends with LANG=C and LC_ALL=C from MAKE_ENV.
# LANG is needed too: the tests' clear_env fixture removes LC_ALL.
do-test:
	${RUN} cd ${WRKSRC} && \
	${SETENV} ${TEST_ENV} LANG=en_US.UTF-8 LC_ALL=en_US.UTF-8 \
		pytest-${PYVERSSUFFIX} -o addopts=${TEST_ADDOPTS:Q} \
		${TEST_PATHS}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
