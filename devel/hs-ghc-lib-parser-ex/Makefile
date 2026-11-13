# $NetBSD: Makefile,v 1.19 2026/11/13 14:38:59 pho Exp $

DISTNAME=	ghc-lib-parser-ex-9.14.2.0
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Programming with GHC parse trees
LICENSE=	modified-bsd

# lib:ghc-lib-parser-ex
.include "../../devel/hs-uniplate/buildlink3.mk"
.include "../../devel/hs-ghc-lib-parser/buildlink3.mk"

# exe:ghc-lib-parser-ex-build-tool
.include "../../misc/hs-extra/buildlink3.mk"
OPTPARSE_APPLICATIVE_EXECUTABLES+=	\
	ghc-lib-parser-ex-build-tool
.include "../../devel/hs-optparse-applicative/application.mk"

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
