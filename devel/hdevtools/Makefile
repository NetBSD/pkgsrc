# $NetBSD: Makefile,v 1.16 2016/01/10 11:49:11 szptvlfn Exp $

DISTNAME=	hdevtools-0.1.0.5
PKGNAME=	${DISTNAME}
PKGREVISION=	15
CATEGORIES=	devel #haskell

MAINTAINER=	szptvlfn@NetBSD.org
COMMENT=	Persistent GHC powered background server for FAST haskell dev tools
LICENSE=	mit


.include "../../mk/haskell.mk"
.include "../../devel/hs-cmdargs/buildlink3.mk"
.include "../../devel/hs-ghc-paths/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
