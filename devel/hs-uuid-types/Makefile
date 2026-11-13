# $NetBSD: Makefile,v 1.20 2026/11/13 14:39:25 pho Exp $

DISTNAME=	uuid-types-1.0.6
PKGREVISION=	4
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
