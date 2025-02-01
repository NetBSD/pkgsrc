# $NetBSD: Makefile,v 1.15 2025/02/01 13:55:43 pho Exp $

DISTNAME=	hackage-security-0.6.2.6
PKGREVISION=	1
CATEGORIES=	security

MAINTAINER=	pho@cielonegro.org
COMMENT=	Hackage security library
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base	\
	filepath	\
	network	\
	template-haskell

.include "../../converters/hs-base16-bytestring/buildlink3.mk"
.include "../../converters/hs-base64-bytestring/buildlink3.mk"
.include "../../security/hs-cryptohash-sha256/buildlink3.mk"
.include "../../security/hs-ed25519/buildlink3.mk"
.include "../../archivers/hs-tar/buildlink3.mk"
.include "../../archivers/hs-zlib/buildlink3.mk"
.include "../../devel/hs-lukko/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../net/hs-network-uri/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
