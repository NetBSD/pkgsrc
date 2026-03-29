# $NetBSD: Makefile,v 1.111 2026/03/29 17:38:30 wiz Exp $

DISTNAME=	astroid-4.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/astroid/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://github.com/pylint-dev/astroid
COMMENT=	Rebuild a new abstract syntax tree from Python's ast
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-mypy>0:../../lang/py-mypy

USE_LANGUAGES=	# none

# as of 4.1.2
# 1 failed, 1929 passed, 80 skipped, 15 xfailed

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4:../../devel/py-typing-extensions
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
