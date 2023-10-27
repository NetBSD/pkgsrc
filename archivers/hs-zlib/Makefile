# $NetBSD: Makefile,v 1.14 2023/10/27 08:13:04 pho Exp $

DISTNAME=	zlib-0.6.3.0
PKGREVISION=	2
CATEGORIES=	archivers

MAINTAINER=	pho@cielonegro.org
COMMENT=	Compression and decompression in the gzip and zlib formats
LICENSE=	modified-bsd

USE_TOOLS+=		pkg-config
CONFIGURE_ARGS+=	-fpkg-config

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base

.include "../../mk/haskell.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
