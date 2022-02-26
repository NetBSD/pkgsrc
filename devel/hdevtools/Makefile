# $NetBSD: Makefile,v 1.24 2022/02/26 03:57:46 pho Exp $

DISTNAME=	hdevtools-0.1.8.0
PKGNAME=	${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel #haskell

MAINTAINER=	szptvlfn@NetBSD.org
COMMENT=	Persistent GHC powered background server for FAST haskell dev tools
LICENSE=	mit

# The upstream is dead atm, and is probably forever.
BROKEN+=	"${PKGBASE} is incompatible with GHC >= 8.8."
BROKEN+=	"Consider using devel/haskell-language-server instead."
BROKEN+=	"See https://github.com/hdevtools/hdevtools/issues/97 for more info."

.include "../../mk/haskell.mk"
.include "../../devel/hs-cmdargs/buildlink3.mk"
.include "../../devel/hs-ghc-paths/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
