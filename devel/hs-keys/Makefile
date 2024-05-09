# $NetBSD: Makefile,v 1.8 2024/05/09 01:32:00 pho Exp $

DISTNAME=	keys-3.12.3
PKGREVISION=	5
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Keyed functors and containers
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	hashable	\
	semigroupoids	\
	transformers

.include "../../math/hs-comonad/buildlink3.mk"
.include "../../math/hs-free/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../math/hs-semigroupoids/buildlink3.mk"
.include "../../math/hs-semigroups/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../devel/hs-transformers-compat/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
