# $NetBSD: Makefile,v 1.10 2023/11/02 06:37:11 pho Exp $

DISTNAME=	comonad-5.0.8
PKGREVISION=	7
CATEGORIES=	math

MAINTAINER=	pho@cielonegro.org
COMMENT=	Comonads, dual of Monads
LICENSE=	2-clause-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	transformers

.include "../../math/hs-distributive/buildlink3.mk"
.include "../../devel/hs-indexed-traversable/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../devel/hs-transformers-compat/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
