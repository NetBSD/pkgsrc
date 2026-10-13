# $NetBSD: Makefile,v 1.21 2026/10/13 09:49:49 wiz Exp $

DISTNAME=	guppy3-3.1.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/guppy3/}

MAINTAINER=	gutteridge@NetBSD.org
HOMEPAGE=	https://github.com/zhuyifei1999/guppy3
COMMENT=	Python programming environment and heap analysis toolset
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk

# https://github.com/zhuyifei1999/guppy3/issues/58
PYTHON_VERSIONS_INCOMPATIBLE=	315

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
