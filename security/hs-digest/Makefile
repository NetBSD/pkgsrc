# $NetBSD: Makefile,v 1.11 2023/10/09 04:54:44 pho Exp $

DISTNAME=	digest-0.0.1.5
PKGREVISION=	2
CATEGORIES=	security

MAINTAINER=	zecrazytux@zecrazytux.net
COMMENT=	Various cryptographic hashes for bytestrings; CRC32 and Adler32
LICENSE=	modified-bsd

USE_TOOLS+=	pkg-config

.include "../../mk/haskell.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
