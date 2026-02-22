# $NetBSD: Makefile,v 1.11 2026/02/22 13:19:11 wiz Exp $

DISTNAME=	hypothesmith-0.3.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hypothesmith/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Zac-HD/hypothesmith
COMMENT=	Hypothesis strategies for generating Python programs, like CSmith
LICENSE=	mpl-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-hypothesis>=6.93.0:../../devel/py-hypothesis
DEPENDS+=	${PYPKGPREFIX}-lark-[0-9]*:../../lang/py-lark
DEPENDS+=	${PYPKGPREFIX}-libcst>=1.0.1:../../lang/py-libcst
TEST_DEPENDS+=	${PYPKGPREFIX}-black-[0-9]*:../../textproc/py-black
TEST_DEPENDS+=	${PYPKGPREFIX}-parso-[0-9]*:../../lang/py-parso
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

# 1 failed, 176 passed, 2 skipped, 3 xfailed, 2 xpassed
# https://github.com/Zac-HD/hypothesmith/issues/38
TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib

PYTHON_VERSIONS_INCOMPATIBLE=	310

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
