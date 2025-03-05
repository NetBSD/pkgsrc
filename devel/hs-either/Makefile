# $NetBSD: Makefile,v 1.14 2025/03/05 03:39:09 pho Exp $

DISTNAME=	either-5.0.2
PKGREVISION=	6
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Combinators for working with sums
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	semigroupoids

.include "../../math/hs-bifunctors/buildlink3.mk"
.include "../../math/hs-profunctors/buildlink3.mk"
.include "../../math/hs-semigroupoids/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
