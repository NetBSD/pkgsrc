# $NetBSD: Makefile,v 1.16 2025/03/05 03:39:42 pho Exp $

DISTNAME=	distributive-0.6.2.1
PKGREVISION=	10
CATEGORIES=	math devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Haskell 98 Distributive functors -- Dual to Traversable
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	transformers

.include "../../devel/hs-base-orphans/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
