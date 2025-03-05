# $NetBSD: Makefile,v 1.15 2025/03/05 03:40:05 pho Exp $

DISTNAME=	unicode-transforms-0.4.0.1
PKGREVISION=	6
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	Unicode normalization
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base		\
	bytestring	\
	ghc-prim	\
	text		\
	unicode-data

.include "../../textproc/hs-unicode-data/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
