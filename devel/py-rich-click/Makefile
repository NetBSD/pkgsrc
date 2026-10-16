# $NetBSD: Makefile,v 1.14 2026/10/16 17:58:20 adam Exp $

DISTNAME=	rich_click-1.9.9
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

PY_RENAME_BINARIES=	rich-click

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
