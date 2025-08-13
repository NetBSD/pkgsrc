# $NetBSD: Makefile,v 1.11 2025/08/13 11:07:18 pho Exp $

DISTNAME=	network-bsd-2.8.1.0
PKGREVISION=	8
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	POSIX network database (<netdb.h>) API
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	deepseq	\
	network

.include "../../net/hs-network/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
