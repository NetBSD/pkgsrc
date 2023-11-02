# $NetBSD: Makefile,v 1.6 2023/11/02 06:37:17 pho Exp $

DISTNAME=	network-bsd-2.8.1.0
PKGREVISION=	4
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	POSIX network database (<netdb.h>) API
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	network

.include "../../net/hs-network/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
