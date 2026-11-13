# $NetBSD: Makefile,v 1.13 2026/11/13 14:39:25 pho Exp $

DISTNAME=	uuid-1.3.16
PKGREVISION=	4
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	For creating, comparing, parsing and printing UUIDs
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	random

.include "../../security/hs-cryptohash-md5/buildlink3.mk"
.include "../../security/hs-cryptohash-sha1/buildlink3.mk"
.include "../../security/hs-entropy/buildlink3.mk"
.include "../../net/hs-network-info/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.include "../../devel/hs-uuid-types/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
