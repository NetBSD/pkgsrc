# $NetBSD: Makefile,v 1.5 2023/10/09 04:54:40 pho Exp $

DISTNAME=	invariant-0.6
PKGREVISION=	2
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Haskell98 invariant functors
LICENSE=	2-clause-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	template-haskell

.include "../../math/hs-bifunctors/buildlink3.mk"
.include "../../math/hs-comonad/buildlink3.mk"
.include "../../math/hs-contravariant/buildlink3.mk"
.include "../../math/hs-profunctors/buildlink3.mk"
.include "../../devel/hs-StateVar/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../devel/hs-th-abstraction/buildlink3.mk"
.include "../../devel/hs-transformers-compat/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
