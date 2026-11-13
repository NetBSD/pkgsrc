# $NetBSD: Makefile,v 1.24 2026/11/13 14:39:02 pho Exp $

DISTNAME=	hint-0.9.0.8
PKGREVISION=	6
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Runtime Haskell interpreter (GHC API wrapper)
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	ghc

.include "../../devel/hs-ghc-paths/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.include "../../sysutils/hs-temporary/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
