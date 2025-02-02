# $NetBSD: Makefile,v 1.16 2025/02/02 13:05:44 pho Exp $

DISTNAME=	digest-0.0.2.1
PKGREVISION=	2
CATEGORIES=	security

MAINTAINER=	zecrazytux@zecrazytux.net
COMMENT=	Various cryptographic hashes for bytestrings; CRC32 and Adler32
LICENSE=	modified-bsd

USE_TOOLS+=	pkg-config
USE_LANGUAGES+=	c++

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
