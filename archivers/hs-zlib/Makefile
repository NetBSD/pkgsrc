# $NetBSD: Makefile,v 1.4 2021/02/18 15:07:28 mef Exp $

DISTNAME=	zlib-0.6.2.1
CATEGORIES=	archivers

MAINTAINER=	pho@cielonegro.org
COMMENT=	Compression and decompression in the gzip and zlib formats
LICENSE=	modified-bsd

BUILDLINK_API_DEPENDS.ghc+=	ghc<8.10
.include "../../mk/haskell.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
