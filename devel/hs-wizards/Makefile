# $NetBSD: Makefile,v 1.9 2023/01/25 13:48:31 pho Exp $

DISTNAME=	wizards-1.0.3
PKGREVISION=	4
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	High level, generic library for interrogative user interfaces
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	haskeline

.include "../../devel/hs-control-monad-free/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
