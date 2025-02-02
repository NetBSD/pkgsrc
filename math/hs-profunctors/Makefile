# $NetBSD: Makefile,v 1.12 2025/02/02 13:05:38 pho Exp $

DISTNAME=	profunctors-5.6.2
PKGREVISION=	9
CATEGORIES=	math

MAINTAINER=	szptvlfn@NetBSD.org
COMMENT=	Profunctors
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base-orphans	\
	transformers

.include "../../devel/hs-base-orphans/buildlink3.mk"
.include "../../math/hs-bifunctors/buildlink3.mk"
.include "../../math/hs-comonad/buildlink3.mk"
.include "../../math/hs-contravariant/buildlink3.mk"
.include "../../math/hs-distributive/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
