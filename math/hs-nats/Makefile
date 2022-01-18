# $NetBSD: Makefile,v 1.15 2022/01/18 02:48:18 pho Exp $

DISTNAME=	nats-1.1.2
PKGREVISION=	2
CATEGORIES=	math

MAINTAINER=	pho@cielonegro.org
COMMENT=	Haskell 98 natural numbers
LICENSE=	modified-bsd

# This package becomes essentially blank when built with GHC >=
# 7.10. Haddock complains when there are no input files.
HASKELL_ENABLE_HADDOCK_DOCUMENTATION=	no

.include "../../mk/haskell.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
