# $NetBSD: Makefile,v 1.13 2023/11/02 06:37:20 pho Exp $

DISTNAME=	digest-0.0.1.7
PKGREVISION=	1
CATEGORIES=	security

MAINTAINER=	zecrazytux@zecrazytux.net
COMMENT=	Various cryptographic hashes for bytestrings; CRC32 and Adler32
LICENSE=	modified-bsd

USE_TOOLS+=	pkg-config

.include "../../mk/haskell.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
