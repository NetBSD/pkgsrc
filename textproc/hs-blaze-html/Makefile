# $NetBSD: Makefile,v 1.18 2023/11/02 06:37:27 pho Exp $

DISTNAME=	blaze-html-0.9.1.2
PKGREVISION=	7
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	Blazingly fast HTML combinator library for Haskell
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	bytestring	\
	text

.include "../../mk/haskell.mk"
.include "../../devel/hs-blaze-builder/buildlink3.mk"
.include "../../textproc/hs-blaze-markup/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
