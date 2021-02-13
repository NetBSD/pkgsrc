# $NetBSD: Makefile,v 1.2 2021/02/13 08:00:59 mef Exp $

DISTNAME=	Decimal-0.5.1
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_HASKELL_HACKAGE:=Decimal-${PKGVERSION_NOREV}/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/PaulJohnson/Haskell-Decimal
COMMENT=	Decimal arithmetic for financial applications
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.ghc+=	ghc<9.0
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
