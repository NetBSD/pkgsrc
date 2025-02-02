# $NetBSD: Makefile,v 1.18 2025/02/02 13:04:55 pho Exp $

DISTNAME=	QuickCheck-2.15.0.1
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Random testing of program properties
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	random

.include "../../devel/hs-random/buildlink3.mk"
.include "../../devel/hs-splitmix/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
