# $NetBSD: Makefile,v 1.9 2023/11/02 06:36:50 pho Exp $

DISTNAME=	pandoc-lua-marshal-0.2.2
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Use pandoc types in Lua
LICENSE=	mit

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	aeson

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../lang/hs-hslua/buildlink3.mk"
.include "../../lang/hs-hslua-list/buildlink3.mk"
.include "../../lang/hs-hslua-marshalling/buildlink3.mk"
.include "../../lang/hs-lua/buildlink3.mk"
.include "../../textproc/hs-pandoc-types/buildlink3.mk"
.include "../../devel/hs-safe/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
