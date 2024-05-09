# $NetBSD: Makefile,v 1.14 2024/05/09 01:32:21 pho Exp $

DISTNAME=	JuicyPixels-3.3.8
PKGREVISION=	4
CATEGORIES=	graphics

MAINTAINER=	pho@cielonegro.org
COMMENT=	Picture loading/serialization
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	bytestring	\
	deepseq		\
	zlib

.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../archivers/hs-zlib/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
