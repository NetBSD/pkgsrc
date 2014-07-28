# $NetBSD: Makefile,v 1.4 2014/07/28 21:38:07 szptvlfn Exp $

DISTNAME=	hdevtools-0.1.0.5
PKGNAME=	${DISTNAME}
PKGREVISION=	3
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
