# $NetBSD: Makefile,v 1.12 2023/11/02 06:36:41 pho Exp $

DISTNAME=	hslua-module-system-1.1.0.1
PKGREVISION=	1
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
