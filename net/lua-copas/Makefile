# $NetBSD: Makefile,v 1.3 2016/06/05 10:06:28 alnsn Exp $

DISTNAME=	copas-2.0.1
PKGNAME=	${DISTNAME:S/copas/${LUA_PKGPREFIX}-copas/}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=keplerproject/}
GITHUB_TAG=	v${PKGVERSION:S/./_/g}
GITHUB_PROJECT=	${DISTNAME:S/-${PKGVERSION_NOREV}//}

MAINTAINER=	alnsn@NetBSD.org
HOMEPAGE=	http://keplerproject.github.io/copas
COMMENT=	Dispatcher based on coroutines that can be used by TCP_IP servers
LICENSE=	mit

DEPENDS+=	${LUA_PKGPREFIX}-coxpcall>=1.16.0:../../devel/lua-coxpcall
DEPENDS+=	${LUA_PKGPREFIX}-socket>=2.0:../../net/lua-socket
DEPENDS+=	${LUA_PKGPREFIX}-sec>=0.6:../../security/lua-sec

MAKE_ENV+=	LUA_LDIR=${LUA_LDIR:Q}

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
