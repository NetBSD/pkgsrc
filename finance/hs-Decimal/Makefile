# $NetBSD: Makefile,v 1.3 2021/02/28 14:08:54 mef Exp $

DISTNAME=	Decimal-0.5.1
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_HASKELL_HACKAGE:=Decimal-${PKGVERSION_NOREV}/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/PaulJohnson/Haskell-Decimal
COMMENT=	Decimal arithmetic for financial applications
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.ghc+=	ghc<=8.10
BUILDLINK_API_DEPENDS.ghc+=	ghc>=8.8
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
