# $NetBSD: Makefile,v 1.7 2014/10/08 21:57:07 szptvlfn Exp $

DISTNAME=	hdevtools-0.1.0.5
PKGNAME=	${DISTNAME}
PKGREVISION=	6
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
