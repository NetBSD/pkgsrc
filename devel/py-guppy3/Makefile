# $NetBSD: Makefile,v 1.20 2026/05/11 12:51:19 adam Exp $

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

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
