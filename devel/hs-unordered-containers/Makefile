# $NetBSD: Makefile,v 1.28 2025/03/05 03:39:34 pho Exp $

DISTNAME=	unordered-containers-0.2.20
PKGREVISION=	3
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Efficient hashing-based container types
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	hashable	\
	template-haskell

.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
