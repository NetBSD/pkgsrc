# $NetBSD: Makefile,v 1.15 2025/08/13 11:06:52 pho Exp $

DISTNAME=	pandoc-lua-marshal-0.3.0
PKGREVISION=	3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Use pandoc types in Lua
LICENSE=	mit

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	hslua-list

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../lang/hs-hslua/buildlink3.mk"
.include "../../lang/hs-hslua-list/buildlink3.mk"
.include "../../lang/hs-hslua-marshalling/buildlink3.mk"
.include "../../lang/hs-lua/buildlink3.mk"
.include "../../textproc/hs-pandoc-types/buildlink3.mk"
.include "../../devel/hs-safe/buildlink3.mk"
.include "../../lang/hs-hslua-list/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
