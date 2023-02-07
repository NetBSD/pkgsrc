# $NetBSD: Makefile,v 1.21 2023/02/07 01:40:53 pho Exp $

DISTNAME=	unordered-containers-0.2.19.1
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Efficient hashing-based container types
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	template-haskell

.include "../../mk/haskell.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
