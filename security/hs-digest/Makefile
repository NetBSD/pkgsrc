# $NetBSD: Makefile,v 1.19 2026/11/13 14:39:42 pho Exp $

DISTNAME=	digest-0.0.2.1
PKGREVISION=	5
CATEGORIES=	security

MAINTAINER=	zecrazytux@zecrazytux.net
COMMENT=	Various cryptographic hashes for bytestrings; CRC32 and Adler32
LICENSE=	modified-bsd

USE_TOOLS+=	pkg-config
USE_LANGUAGES+=	c++

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
