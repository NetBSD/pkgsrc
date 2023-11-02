# $NetBSD: Makefile,v 1.11 2023/11/02 06:37:40 pho Exp $

DISTNAME=	unicode-transforms-0.4.0.1
PKGREVISION=	3
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	Unicode normalization
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base	\
	ghc-prim	\
	unicode-data

.include "../../textproc/hs-unicode-data/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
