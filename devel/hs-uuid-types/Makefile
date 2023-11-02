# $NetBSD: Makefile,v 1.14 2023/11/02 06:37:03 pho Exp $

DISTNAME=	uuid-types-1.0.5.1
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Type definitions for Universally Unique Identifiers
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	hashable	\
	template-haskell	\
	text

.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
