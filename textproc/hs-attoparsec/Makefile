# $NetBSD: Makefile,v 1.27 2025/03/05 03:39:55 pho Exp $

DISTNAME=	attoparsec-0.14.4
PKGREVISION=	8
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	Fast combinator parsing for bytestrings and text
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	bytestring	\
	ghc-prim

.include "../../math/hs-scientific/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
