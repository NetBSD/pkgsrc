# $NetBSD: Makefile,v 1.12 2023/10/27 13:09:23 pho Exp $

DISTNAME=	distributive-0.6.2.1
PKGREVISION=	6
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
