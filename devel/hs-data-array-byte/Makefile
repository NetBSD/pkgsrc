# $NetBSD: Makefile,v 1.1 2023/01/26 03:17:46 pho Exp $

DISTNAME=	data-array-byte-0.1.0.1
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Compatibility layer for Data.Array.Byte
LICENSE=	modified-bsd

# NOTE: This package is only needed on GHC < 9.4. The lack of PLIST is
# intentional, as it becomes empty when it's built with GHC >= 9.4.

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
