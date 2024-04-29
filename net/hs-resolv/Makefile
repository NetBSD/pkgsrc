# $NetBSD: Makefile,v 1.14 2024/04/29 04:35:38 pho Exp $

DISTNAME=	resolv-0.2.0.2
PKGREVISION=	1
CATEGORIES=	net

MAINTAINER=	pho@cielonegro.org
COMMENT=	Domain Name Service (DNS) lookup
LICENSE=	gnu-gpl-v2

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	bytestring

.include "../../converters/hs-base16-bytestring/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
