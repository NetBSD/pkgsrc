# $NetBSD: Makefile,v 1.1.1.1 2015/04/20 19:34:47 alnsn Exp $

DISTNAME=	lupa-1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://pypi.python.org/packages/source/l/lupa/

MAINTAINER=	alnsn@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/lupa
COMMENT=	Python wrapper around Lua and LuaJIT
LICENSE=	mit

USE_TOOLS+=	pkg-config

.include "options.mk"

.include "../../lang/python/distutils.mk"
.include "../../lang/LuaJIT2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
