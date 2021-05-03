# $NetBSD: Makefile,v 1.14 2021/05/03 19:01:08 pho Exp $

DISTNAME=	nats-1.1.2
PKGREVISION=	1
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
