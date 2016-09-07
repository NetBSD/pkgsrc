# $NetBSD: Makefile,v 1.3 2016/09/07 21:56:21 alnsn Exp $

DISTNAME=	lupa-1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lupa/}

MAINTAINER=	alnsn@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/lupa
COMMENT=	Python wrapper around Lua and LuaJIT
LICENSE=	mit

USE_TOOLS+=	pkg-config

.include "options.mk"

.include "../../lang/python/distutils.mk"
.include "../../lang/LuaJIT2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
