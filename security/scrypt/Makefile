# $NetBSD: Makefile,v 1.11 2023/10/24 22:10:59 wiz Exp $

DISTNAME=	scrypt-1.3.1
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://www.tarsnap.com/scrypt/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	https://www.tarsnap.com/scrypt/
COMMENT=	Encrypt and decrypt files
LICENSE=	2-clause-bsd

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
TEST_TARGET=		test
UNLIMIT_RESOURCES=	datasize

CONFIGURE_ARGS+=	--enable-libscrypt-kdf

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
