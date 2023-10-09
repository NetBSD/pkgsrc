# $NetBSD: Makefile,v 1.5 2023/10/09 04:54:42 pho Exp $

DISTNAME=	network-bsd-2.8.1.0
PKGREVISION=	3
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	POSIX network database (<netdb.h>) API
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	network

.include "../../net/hs-network/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
