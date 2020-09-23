# $NetBSD: Makefile,v 1.12 2020/09/23 21:40:16 mef Exp $

DISTNAME=	nats-1.1.2
CATEGORIES=	math

MAINTAINER=	pho@cielonegro.org
COMMENT=	Haskell 98 natural numbers
LICENSE=	modified-bsd

# This package becomes essentially blank when built with GHC >=
# 7.10. Haddock complains when there are no input files.
HASKELL_ENABLE_HADDOCK_DOCUMENTATION=	no

PLIST_SUBST+=	HASKELL_VERSION=${_HASKELL_VERSION:Q}

.include "../../mk/haskell.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
