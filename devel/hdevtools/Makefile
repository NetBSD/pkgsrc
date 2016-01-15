# $NetBSD: Makefile,v 1.17 2016/01/15 15:26:39 szptvlfn Exp $

DISTNAME=	hdevtools-0.1.2.2
PKGNAME=	${DISTNAME}
CATEGORIES=	devel #haskell

MAINTAINER=	szptvlfn@NetBSD.org
COMMENT=	Persistent GHC powered background server for FAST haskell dev tools
LICENSE=	mit


.include "../../mk/haskell.mk"
.include "../../devel/hs-cmdargs/buildlink3.mk"
.include "../../devel/hs-ghc-paths/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../devel/hs-transformers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
