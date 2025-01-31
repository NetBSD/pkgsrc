# $NetBSD: Makefile,v 1.11 2025/01/31 02:13:46 pho Exp $

DISTNAME=	ghc-lib-parser-9.12.1.20250105
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	The GHC API, decoupled from GHC versions
LICENSE=	modified-bsd

USE_TOOLS+=	alex happy

# Uses more than 5 GiB of memory to compile when -O2 is in effect.
HASKELL_OPTIMIZATION_LEVEL=	1

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
