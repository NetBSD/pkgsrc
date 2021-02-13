# $NetBSD: Makefile,v 1.3 2021/02/13 08:00:57 mef Exp $

DISTNAME=	zlib-0.6.2.1
CATEGORIES=	archivers

MAINTAINER=	pho@cielonegro.org
COMMENT=	Compression and decompression in the gzip and zlib formats
LICENSE=	modified-bsd

BUILDLINK_API_DEPENDS.ghc+=	ghc<9.0
.include "../../mk/haskell.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
