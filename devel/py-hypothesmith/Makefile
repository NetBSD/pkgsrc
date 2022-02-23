# $NetBSD: Makefile,v 1.1 2022/02/23 11:40:06 wiz Exp $

DISTNAME=	hypothesmith-0.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hypothesmith/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Zac-HD/hypothesmith
COMMENT=	Hypothesis strategies for generating Python programs, like CSmith
LICENSE=	mpl-2.0

DEPENDS+=	${PYPKGPREFIX}-libcst-[0-9]*:../../lang/py-libcst
DEPENDS+=	${PYPKGPREFIX}-lark-parser-[0-9]*:../../lang/py-lark-parser
DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-black-[0-9]*:../../textproc/py-black
TEST_DEPENDS+=	${PYPKGPREFIX}-parso-[0-9]*:../../lang/py-parso
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

# as of 0.2.0
# 1 failed, 170 passed, 2 skipped, 3 xfailed
# https://github.com/Zac-HD/hypothesmith/issues/21
TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
