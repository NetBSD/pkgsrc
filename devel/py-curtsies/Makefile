# $NetBSD: Makefile,v 1.21 2026/10/16 19:43:46 adam Exp $

DISTNAME=	curtsies-0.4.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/curtsies/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bpython/curtsies
COMMENT=	Curses-like terminal wrapper, with colored strings
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-blessed>=1.5:../../devel/py-blessed
DEPENDS+=	${PYPKGPREFIX}-cwcwidth-[0-9]*:../../devel/py-cwcwidth
TEST_DEPENDS+=	${PYPKGPREFIX}-pyte-[0-9]*:../../devel/py-pyte

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	311

# as of 0.4.2
# 8 failed, 69 passed, 26 skipped

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
