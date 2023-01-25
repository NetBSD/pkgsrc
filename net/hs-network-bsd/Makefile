# $NetBSD: Makefile,v 1.3 2023/01/25 10:21:49 pho Exp $

DISTNAME=	network-bsd-2.8.1.0
PKGREVISION=	1
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	POSIX network database (<netdb.h>) API
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	network

.include "../../net/hs-network/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
