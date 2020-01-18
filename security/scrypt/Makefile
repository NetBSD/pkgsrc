# $NetBSD: Makefile,v 1.8 2020/01/18 21:50:47 jperkin Exp $

DISTNAME=	scrypt-1.3.0
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://www.tarsnap.com/scrypt/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	https://www.tarsnap.com/scrypt/
COMMENT=	Encrypt and decrypt files
LICENSE=	2-clause-bsd

GNU_CONFIGURE=		yes
TEST_TARGET=		test
UNLIMIT_RESOURCES=	datasize

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
