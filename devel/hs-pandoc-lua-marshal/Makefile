# $NetBSD: Makefile,v 1.4 2022/08/20 08:08:18 wiz Exp $

DISTNAME=	pandoc-lua-marshal-0.1.4
PKGREVISION=	3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Use pandoc types in Lua
LICENSE=	mit

.include "../../lang/hs-hslua/buildlink3.mk"
.include "../../lang/hs-hslua-marshalling/buildlink3.mk"
.include "../../lang/hs-lua/buildlink3.mk"
.include "../../textproc/hs-pandoc-types/buildlink3.mk"
.include "../../devel/hs-safe/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
