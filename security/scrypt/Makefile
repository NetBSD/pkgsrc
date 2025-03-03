# $NetBSD: Makefile,v 1.12 2025/03/03 20:29:31 wiz Exp $

DISTNAME=	scrypt-1.3.1
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://www.tarsnap.com/scrypt/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
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
