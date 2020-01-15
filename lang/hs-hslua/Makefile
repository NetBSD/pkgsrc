# $NetBSD: Makefile,v 1.1 2020/01/15 12:40:38 pho Exp $

DISTNAME=	hslua-1.0.3.2
CATEGORIES=	lang

MAINTAINER=	szptvlfn@NetBSD.org
COMMENT=	Bindings to Lua, an embeddable scripting language
LICENSE=	mit

USE_TOOLS+=		pkg-config
CONFIGURE_ARGS+=	-fpkg-config

.include "../../devel/hs-exceptions/buildlink3.mk"
.include "../../devel/hs-fail/buildlink3.mk"
# This package explicitly depends on Lua 5.3.x so including
# ../../lang/lua/buildlink3.mk would be inappropriate.
.include "../../lang/lua53/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
