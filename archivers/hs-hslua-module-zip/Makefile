# $NetBSD: Makefile,v 1.7 2024/05/09 01:31:38 pho Exp $

DISTNAME=	hslua-module-zip-1.1.1
PKGREVISION=	1
CATEGORIES=	archivers

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Lua module to work with file zips
LICENSE=	mit

.include "../../lang/hs-hslua-core/buildlink3.mk"
.include "../../lang/hs-hslua-list/buildlink3.mk"
.include "../../lang/hs-hslua-marshalling/buildlink3.mk"
.include "../../lang/hs-hslua-packaging/buildlink3.mk"
.include "../../lang/hs-hslua-typing/buildlink3.mk"
.include "../../archivers/hs-zip-archive/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
