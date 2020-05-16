# $NetBSD: Makefile,v 1.5 2020/05/16 07:08:08 adam Exp $

DISTNAME=	guppy3-3.0.10.post1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/post//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/guppy3/}

MAINTAINER=	gutteridge@NetBSD.org
HOMEPAGE=	https://github.com/zhuyifei1999/guppy3
COMMENT=	Python programming environment and heap analysis toolset
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
