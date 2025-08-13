# $NetBSD: Makefile,v 1.16 2025/08/13 11:07:19 pho Exp $

DISTNAME=	network-uri-2.6.4.2
PKGREVISION=	7
CATEGORIES=	net

MAINTAINER=	pho@cielonegro.org
COMMENT=	URI manipulation
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	deepseq

.include "../../devel/hs-th-compat/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
