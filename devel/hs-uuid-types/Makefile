# $NetBSD: Makefile,v 1.16 2025/01/30 04:27:04 pho Exp $

DISTNAME=	uuid-types-1.0.6
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Type definitions for Universally Unique Identifiers
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	hashable	\
	random

.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
