# $NetBSD: Makefile,v 1.21 2026/07/16 19:31:18 wiz Exp $

DISTNAME=	codespell-2.4.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/codespell/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/codespell-project/codespell
COMMENT=	Check code for common misspellings
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=6.2:../../devel/py-setuptools_scm
TEST_DEPENDS+=	${PYPKGPREFIX}-chardet-[0-9]*:../../converters/py-chardet
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-dependency-[0-9]*:../../devel/py-test-dependency

USE_LANGUAGES=	# none

REPLACE_PYTHON=	bin/codespell
REPLACE_BASH+=	tools/gen_OX.sh

PY_RENAME_BINARIES=	codespell

# test status as of 2.4.3
# 3 failed, 122 passed, 17 skipped

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
