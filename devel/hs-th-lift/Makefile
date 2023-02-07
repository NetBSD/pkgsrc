# $NetBSD: Makefile,v 1.7 2023/02/07 01:40:52 pho Exp $

DISTNAME=	th-lift-0.8.2
PKGREVISION=	5
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Derive Template Haskell's Lift class for datatypes
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	template-haskell

.include "../../devel/hs-th-abstraction/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
