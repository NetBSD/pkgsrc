# $NetBSD: Makefile,v 1.2 2021/02/13 08:00:59 mef Exp $

DISTNAME=	resolv-0.1.1.3
CATEGORIES=	net

MAINTAINER=	pho@cielonegro.org
COMMENT=	Domain Name Service (DNS) lookup
LICENSE=	gnu-gpl-v2

.include "../../converters/hs-base16-bytestring/buildlink3.mk"
BUILDLINK_API_DEPENDS.ghc+=	ghc<9.0
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
