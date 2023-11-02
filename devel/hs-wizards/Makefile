# $NetBSD: Makefile,v 1.13 2023/11/02 06:37:05 pho Exp $

DISTNAME=	wizards-1.0.3
PKGREVISION=	7
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	High level, generic library for interrogative user interfaces
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	haskeline	\
	mtl	\
	transformers

.include "../../devel/hs-control-monad-free/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
