# $NetBSD: Makefile,v 1.8 2023/02/07 01:40:27 pho Exp $

DISTNAME=	assoc-1.0.2
PKGREVISION=	5
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
