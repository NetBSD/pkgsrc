# $NetBSD: Makefile,v 1.3 2021/02/28 14:19:37 mef Exp $

DISTNAME=	wizards-1.0.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_HASKELL_HACKAGE:=wizards-${PKGVERSION_NOREV}/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://hackage.haskell.org/package/wizards
COMMENT=	High level, generic library for interrogative user interfaces
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

.include "../../devel/hs-control-monad-free/buildlink3.mk"
BUILDLINK_API_DEPENDS.ghc+=	ghc<=8.10
BUILDLINK_API_DEPENDS.ghc+=	ghc>=8.8
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
