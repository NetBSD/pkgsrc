# $NetBSD: Makefile,v 1.9 2023/02/07 01:40:56 pho Exp $

DISTNAME=	hslua-2.2.1
PKGREVISION=	1
CATEGORIES=	lang

MAINTAINER=	szptvlfn@NetBSD.org
COMMENT=	Bindings to Lua, an embeddable scripting language
LICENSE=	mit

.include "../../converters/hs-hslua-aeson/buildlink3.mk"
.include "../../lang/hs-hslua-classes/buildlink3.mk"
.include "../../lang/hs-hslua-core/buildlink3.mk"
.include "../../lang/hs-hslua-marshalling/buildlink3.mk"
.include "../../lang/hs-hslua-objectorientation/buildlink3.mk"
.include "../../lang/hs-hslua-packaging/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
