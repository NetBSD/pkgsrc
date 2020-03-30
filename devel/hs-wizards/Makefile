# $NetBSD: Makefile,v 1.1 2020/03/30 16:43:35 riastradh Exp $

DISTNAME=	wizards-1.0.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_HASKELL_HACKAGE:=wizards-${PKGVERSION_NOREV}/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://hackage.haskell.org/package/wizards
COMMENT=	High level, generic library for interrogative user interfaces
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

.include "../../devel/hs-control-monad-free/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
