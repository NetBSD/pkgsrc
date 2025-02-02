# $NetBSD: Makefile,v 1.17 2025/02/02 13:05:41 pho Exp $

DISTNAME=	resolv-0.2.0.2
PKGREVISION=	3
CATEGORIES=	net

MAINTAINER=	pho@cielonegro.org
COMMENT=	Domain Name Service (DNS) lookup
LICENSE=	gnu-gpl-v2

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	bytestring	\
	containers

.include "../../converters/hs-base16-bytestring/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
