# $NetBSD: Makefile,v 1.15 2024/10/17 09:22:45 wiz Exp $

DISTNAME=	curtsies-0.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/curtsies/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bpython/curtsies
COMMENT=	Curses-like terminal wrapper, with colored strings
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-blessed>=1.5:../../devel/py-blessed
DEPENDS+=	${PYPKGPREFIX}-cwcwidth-[0-9]*:../../devel/py-cwcwidth
TEST_DEPENDS+=	${PYPKGPREFIX}-pyte-[0-9]*:../../devel/py-pyte

USE_LANGUAGES=	# none

# as of 0.4.2
# 8 failed, 69 passed, 26 skipped

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
