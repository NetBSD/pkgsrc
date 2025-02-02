# $NetBSD: Makefile,v 1.16 2025/02/02 13:05:31 pho Exp $

DISTNAME=	wizards-1.0.3
PKGREVISION=	9
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
