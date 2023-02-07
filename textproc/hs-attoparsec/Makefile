# $NetBSD: Makefile,v 1.21 2023/02/07 01:41:07 pho Exp $

DISTNAME=	attoparsec-0.14.4
PKGREVISION=	3
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	Fast combinator parsing for bytestrings and text
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	ghc-prim

.include "../../math/hs-scientific/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
