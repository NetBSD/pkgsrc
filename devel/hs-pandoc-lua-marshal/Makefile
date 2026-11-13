# $NetBSD: Makefile,v 1.16 2026/11/13 14:39:10 pho Exp $

DISTNAME=	pandoc-lua-marshal-0.3.0
PKGREVISION=	4
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
