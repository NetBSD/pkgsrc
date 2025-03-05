# $NetBSD: Makefile,v 1.15 2025/03/05 03:39:47 pho Exp $

DISTNAME=	network-uri-2.6.4.2
PKGREVISION=	6
CATEGORIES=	net

MAINTAINER=	pho@cielonegro.org
COMMENT=	URI manipulation
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	deepseq

.include "../../devel/hs-th-compat/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
