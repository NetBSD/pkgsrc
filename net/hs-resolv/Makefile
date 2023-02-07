# $NetBSD: Makefile,v 1.10 2023/02/07 01:41:02 pho Exp $

DISTNAME=	resolv-0.1.2.0
PKGREVISION=	5
CATEGORIES=	net

MAINTAINER=	pho@cielonegro.org
COMMENT=	Domain Name Service (DNS) lookup
LICENSE=	gnu-gpl-v2

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base	\
	base16-bytestring	\
	bytestring

.include "../../converters/hs-base16-bytestring/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
