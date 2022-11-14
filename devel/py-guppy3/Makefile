# $NetBSD: Makefile,v 1.10 2022/11/14 22:06:02 wiz Exp $

DISTNAME=	guppy3-3.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/guppy3/}

MAINTAINER=	gutteridge@NetBSD.org
HOMEPAGE=	https://github.com/zhuyifei1999/guppy3
COMMENT=	Python programming environment and heap analysis toolset
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk

# no 3.11 support as of 3.1.2
# https://github.com/zhuyifei1999/guppy3/issues/41
PYTHON_VERSIONS_INCOMPATIBLE=	27 311

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
