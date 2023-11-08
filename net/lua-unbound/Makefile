# $NetBSD: Makefile,v 1.6 2023/11/08 13:20:31 wiz Exp $

DISTNAME=	luaunbound-1.0.0
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/lua//}
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	https://code.zash.se/dl/luaunbound/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://code.zash.se/dl/luaunbound/
COMMENT=	Binding of libunbound for the Lua language
LICENSE=	modified-bsd

USE_TOOLS+=	gmake pkg-config
MAKE_FILE=	GNUmakefile
MAKE_FLAGS+=	LUA_VERSION=${_LUA_DOT_VERSION}

LUA_VERSIONS_ACCEPTED=	54 53 52 51

.include "../../lang/lua/module.mk"
.include "../../net/unbound/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
