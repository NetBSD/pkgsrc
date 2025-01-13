# $NetBSD: Makefile,v 1.15 2025/01/13 23:34:20 gutteridge Exp $

DISTNAME=	guppy3-3.1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/guppy3/}

MAINTAINER=	gutteridge@NetBSD.org
HOMEPAGE=	https://github.com/zhuyifei1999/guppy3
COMMENT=	Python programming environment and heap analysis toolset
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
