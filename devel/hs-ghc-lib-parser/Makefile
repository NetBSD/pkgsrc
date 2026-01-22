# $NetBSD: Makefile,v 1.16 2026/01/22 07:21:34 wiz Exp $

DISTNAME=	ghc-lib-parser-9.14.1.20251220
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	The GHC API, decoupled from GHC versions
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	alex happy

USE_TOOLS+=	alex happy

# Uses more than 5 GiB of memory to compile when -O2 is in effect.
HASKELL_OPTIMIZATION_LEVEL=	1

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
