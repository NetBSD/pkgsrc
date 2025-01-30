# $NetBSD: Makefile,v 1.15 2025/01/30 14:23:40 pho Exp $

DISTNAME=	hslua-module-system-1.1.2
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Lua module wrapper around Haskell System module
LICENSE=	mit

.include "../../lang/hs-hslua-core/buildlink3.mk"
.include "../../lang/hs-hslua-marshalling/buildlink3.mk"
.include "../../lang/hs-hslua-packaging/buildlink3.mk"
.include "../../sysutils/hs-temporary/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
