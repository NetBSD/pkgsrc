# $NetBSD: Makefile,v 1.11 2024/04/29 04:55:33 pho Exp $

DISTNAME=	th-lift-0.8.4
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Derive Template Haskell's Lift class for datatypes
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	th-abstraction

.include "../../devel/hs-th-abstraction/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
