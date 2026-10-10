# $NetBSD: Makefile,v 1.11 2026/10/10 10:43:53 adam Exp $

DISTNAME=	future-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/future/}

MAINTAINER=	gde@llew.me
#HOMEPAGE=	https://python-future.org/
COMMENT=	Clean single-source support for Python 3 and 2
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	futurize pasteurize

# as of 1.0.0
# 26 failed, 1024 passed, 47 skipped, 46 xfailed, 48 warnings
# with
#ALLOW_NETWORK_ACCESS=	yes
# 2 failed, 1058 passed, 37 skipped, 46 xfailed, 48 warnings

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
