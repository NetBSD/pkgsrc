# $NetBSD: Makefile,v 1.19 2025/08/13 11:07:19 pho Exp $

DISTNAME=	resolv-0.2.0.2
PKGREVISION=	5
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
