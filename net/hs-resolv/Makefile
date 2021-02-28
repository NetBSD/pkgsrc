# $NetBSD: Makefile,v 1.3 2021/02/28 14:27:03 mef Exp $

DISTNAME=	resolv-0.1.1.3
CATEGORIES=	net

MAINTAINER=	pho@cielonegro.org
COMMENT=	Domain Name Service (DNS) lookup
LICENSE=	gnu-gpl-v2

.include "../../converters/hs-base16-bytestring/buildlink3.mk"
BUILDLINK_API_DEPENDS.ghc+=	ghc<=8.10
BUILDLINK_API_DEPENDS.ghc+=	ghc>=8.8
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
