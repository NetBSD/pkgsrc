# $NetBSD: Makefile,v 1.17 2025/02/02 13:05:29 pho Exp $

DISTNAME=	uuid-types-1.0.6
PKGREVISION=	1
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
