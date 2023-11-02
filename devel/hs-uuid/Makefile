# $NetBSD: Makefile,v 1.6 2023/11/02 06:37:03 pho Exp $

DISTNAME=	uuid-1.3.15
PKGREVISION=	4
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	For creating, comparing, parsing and printing UUIDs
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	text	\
	time

.include "../../security/hs-cryptohash-md5/buildlink3.mk"
.include "../../security/hs-cryptohash-sha1/buildlink3.mk"
.include "../../security/hs-entropy/buildlink3.mk"
.include "../../net/hs-network-info/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.include "../../devel/hs-uuid-types/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
