# $NetBSD: Makefile,v 1.19 2026/11/13 14:39:27 pho Exp $

DISTNAME=	wizards-1.0.3
PKGREVISION=	12
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	High level, generic library for interrogative user interfaces
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	containers	\
	haskeline	\
	mtl	\
	transformers

.include "../../devel/hs-control-monad-free/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
