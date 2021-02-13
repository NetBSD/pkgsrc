# $NetBSD: Makefile,v 1.2 2021/02/13 08:00:59 mef Exp $

DISTNAME=	wizards-1.0.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_HASKELL_HACKAGE:=wizards-${PKGVERSION_NOREV}/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://hackage.haskell.org/package/wizards
COMMENT=	High level, generic library for interrogative user interfaces
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

.include "../../devel/hs-control-monad-free/buildlink3.mk"
BUILDLINK_API_DEPENDS.ghc+=	ghc<9.0
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
