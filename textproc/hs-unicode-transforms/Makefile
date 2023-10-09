# $NetBSD: Makefile,v 1.10 2023/10/09 04:54:56 pho Exp $

DISTNAME=	unicode-transforms-0.4.0.1
PKGREVISION=	2
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
