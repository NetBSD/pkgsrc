# $NetBSD: Makefile,v 1.7 2023/11/02 06:37:12 pho Exp $

DISTNAME=	free-5.2
PKGREVISION=	1
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Monads for free
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	semigroupoids	\
	th-abstraction

.include "../../math/hs-comonad/buildlink3.mk"
.include "../../math/hs-distributive/buildlink3.mk"
.include "../../devel/hs-indexed-traversable/buildlink3.mk"
.include "../../math/hs-profunctors/buildlink3.mk"
.include "../../math/hs-semigroupoids/buildlink3.mk"
.include "../../devel/hs-th-abstraction/buildlink3.mk"
.include "../../devel/hs-transformers-base/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
