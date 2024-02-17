# $NetBSD: Makefile,v 1.6 2024/02/17 02:13:10 adam Exp $

DISTNAME=	hypothesmith-0.3.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hypothesmith/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Zac-HD/hypothesmith
COMMENT=	Hypothesis strategies for generating Python programs, like CSmith
LICENSE=	mpl-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-hypothesis>=6.93.0:../../devel/py-hypothesis
DEPENDS+=	${PYPKGPREFIX}-lark-parser-[0-9]*:../../lang/py-lark-parser
DEPENDS+=	${PYPKGPREFIX}-libcst>=1.0.1:../../lang/py-libcst
TEST_DEPENDS+=	${PYPKGPREFIX}-black-[0-9]*:../../textproc/py-black
TEST_DEPENDS+=	${PYPKGPREFIX}-parso-[0-9]*:../../lang/py-parso
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

# as of 0.2.0
# 1 failed, 170 passed, 2 skipped, 3 xfailed
# https://github.com/Zac-HD/hypothesmith/issues/21
TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
