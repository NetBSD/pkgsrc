# $NetBSD: Makefile,v 1.17 2025/03/05 03:39:36 pho Exp $

DISTNAME=	wizards-1.0.3
PKGREVISION=	10
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
