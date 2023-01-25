# $NetBSD: Makefile,v 1.6 2023/01/25 13:51:13 pho Exp $

DISTNAME=	th-lift-0.8.2
PKGREVISION=	4
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Derive Template Haskell's Lift class for datatypes
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	template-haskell

.include "../../devel/hs-th-abstraction/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
