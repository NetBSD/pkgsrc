# $NetBSD: Makefile,v 1.10 2022/02/26 03:57:43 pho Exp $

DISTNAME=	zlib-0.6.2.3
PKGREVISION=	4
CATEGORIES=	archivers

MAINTAINER=	pho@cielonegro.org
COMMENT=	Compression and decompression in the gzip and zlib formats
LICENSE=	modified-bsd

USE_TOOLS+=		pkg-config
CONFIGURE_ARGS+=	-fpkg-config

.include "../../mk/haskell.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
