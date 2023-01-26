# $NetBSD: Makefile,v 1.7 2023/01/26 11:18:42 pho Exp $

DISTNAME=	assoc-1.0.2
PKGREVISION=	4
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Symmetric and Semigroupy Bifunctors
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base

.include "../../mk/haskell.mk"
.include "../../math/hs-bifunctors/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
