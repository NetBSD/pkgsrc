# $NetBSD: Makefile,v 1.19 2026/01/06 08:02:06 wiz Exp $

DISTNAME=	guppy3-3.1.6
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
