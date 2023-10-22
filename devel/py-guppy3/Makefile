# $NetBSD: Makefile,v 1.12 2023/10/22 11:34:58 wiz Exp $

DISTNAME=	guppy3-3.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/guppy3/}

MAINTAINER=	gutteridge@NetBSD.org
HOMEPAGE=	https://github.com/zhuyifei1999/guppy3
COMMENT=	Python programming environment and heap analysis toolset
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk

PYTHON_VERSIONS_INCOMPATIBLE=	27 312

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
