# $NetBSD: Makefile,v 1.12 2026/11/13 14:39:38 pho Exp $

DISTNAME=	network-bsd-2.8.1.0
PKGREVISION=	9
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
