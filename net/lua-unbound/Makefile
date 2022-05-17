# $NetBSD: Makefile,v 1.2 2022/05/17 11:31:16 nia Exp $

DISTNAME=	luaunbound-1.0.0
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/lua//}
CATEGORIES=	net
MASTER_SITES=	https://code.zash.se/dl/luaunbound/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://code.zash.se/dl/luaunbound/
COMMENT=	Binding of libunbound for the Lua language
LICENSE=	modified-bsd

USE_TOOLS+=	gmake pkg-config
MAKE_FILE=	GNUmakefile

LUA_VERSIONS_ACCEPTED=	52

.include "../../lang/lua/module.mk"
.include "../../net/unbound/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
