# $NetBSD: Makefile,v 1.5 2022/01/18 02:48:07 pho Exp $

DISTNAME=	fail-4.9.0.0
PKGREVISION=	2
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Forward-compatible MonadFail class
LICENSE=	modified-bsd

# This package becomes essentially blank when built with GHC >=
# 8.0. Haddock complains when there are no input files.
HASKELL_ENABLE_HADDOCK_DOCUMENTATION=	no

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
