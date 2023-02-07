# $NetBSD: Makefile,v 1.24 2023/02/07 01:40:36 pho Exp $

DISTNAME=	hashable-1.4.2.0
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Class for types that can be converted to a hash value
LICENSE=	modified-bsd

.include "../../devel/hs-data-array-byte/buildlink3.mk" # Only required on GHC < 9.4
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
