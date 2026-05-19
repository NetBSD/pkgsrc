# $NetBSD: Makefile,v 1.11 2026/05/19 13:09:02 adam Exp $

DISTNAME=	rich_click-1.9.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rich-click/}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/ewels/rich-click
COMMENT=	Format click help output nicely with rich
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-click>=8:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-rich>=12:../../comms/py-rich

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4:../../devel/py-typing-extensions
.endif

PY_RENAME_BINARIES=	rich-click

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
