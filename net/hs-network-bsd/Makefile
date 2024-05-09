# $NetBSD: Makefile,v 1.8 2024/05/09 01:32:30 pho Exp $

DISTNAME=	network-bsd-2.8.1.0
PKGREVISION=	5
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
