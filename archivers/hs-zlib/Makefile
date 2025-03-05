# $NetBSD: Makefile,v 1.19 2025/03/05 03:38:55 pho Exp $

DISTNAME=	zlib-0.7.1.0
PKGREVISION=	3
CATEGORIES=	archivers

MAINTAINER=	pho@cielonegro.org
COMMENT=	Compression and decompression in the gzip and zlib formats
LICENSE=	modified-bsd

USE_TOOLS+=		pkg-config
CONFIGURE_ARGS+=	-fpkg-config

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
