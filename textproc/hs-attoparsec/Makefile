# $NetBSD: Makefile,v 1.20 2023/01/26 09:40:55 pho Exp $

DISTNAME=	attoparsec-0.14.4
PKGREVISION=	2
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	Fast combinator parsing for bytestrings and text
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	ghc-prim

.include "../../math/hs-scientific/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
