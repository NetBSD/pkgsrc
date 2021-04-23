# $NetBSD: Makefile,v 1.3 2021/04/23 06:18:23 pho Exp $

DISTNAME=	fail-4.9.0.0
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Forward-compatible MonadFail class
LICENSE=	modified-bsd

# This package becomes essentially blank when built with GHC >=
# 8.0. Haddock complains when there are no input files.
HASKELL_ENABLE_HADDOCK_DOCUMENTATION=	no

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
