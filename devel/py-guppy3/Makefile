# $NetBSD: Makefile,v 1.1 2019/10/04 22:11:59 gutteridge Exp $

DISTNAME=	guppy3-3.0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/guppy3/}

MAINTAINER=	gutteridge@NetBSD.org
HOMEPAGE=	https://github.com/zhuyifei1999/guppy3
COMMENT=	Python programming environment and heap analysis toolset
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	c

DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
