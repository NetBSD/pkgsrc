# $NetBSD: Makefile,v 1.5 2017/04/26 14:54:59 wiz Exp $

DISTNAME=	scrypt-1.2.1
CATEGORIES=	security
MASTER_SITES=	https://www.tarsnap.com/scrypt/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	https://www.tarsnap.com/scrypt/
COMMENT=	Encrypt and decrypt files
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
TEST_TARGET=	test
UNLIMIT_RESOURCES=	datasize

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
