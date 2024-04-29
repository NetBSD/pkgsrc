# $NetBSD: Makefile,v 1.9 2024/04/29 09:29:57 pho Exp $

DISTNAME=	ghc-lib-parser-9.8.2.20240223
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	The GHC API, decoupled from GHC versions
LICENSE=	modified-bsd

USE_TOOLS+=	alex happy

# Uses more than 5 GiB of memory to compile when -O2 is in effect.
HASKELL_OPTIMIZATION_LEVEL=	1

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
