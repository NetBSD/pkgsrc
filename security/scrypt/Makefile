# $NetBSD: Makefile,v 1.3 2015/08/23 14:42:30 wiz Exp $

DISTNAME=	scrypt-1.2.0
CATEGORIES=	security
MASTER_SITES=	https://www.tarsnap.com/scrypt/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	https://www.tarsnap.com/scrypt/
COMMENT=	Encrypt and decrypt files
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
