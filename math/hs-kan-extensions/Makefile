# $NetBSD: Makefile,v 1.8 2024/05/09 01:32:26 pho Exp $

DISTNAME=	kan-extensions-5.2.5
PKGREVISION=	4
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Kan extensions/lifts, the Yoneda lemma, and (co)density (co)monads
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	semigroupoids

.include "../../math/hs-adjunctions/buildlink3.mk"
.include "../../math/hs-comonad/buildlink3.mk"
.include "../../math/hs-contravariant/buildlink3.mk"
.include "../../math/hs-distributive/buildlink3.mk"
.include "../../math/hs-free/buildlink3.mk"
.include "../../math/hs-invariant/buildlink3.mk"
.include "../../math/hs-profunctors/buildlink3.mk"
.include "../../math/hs-semigroupoids/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../devel/hs-transformers-compat/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
