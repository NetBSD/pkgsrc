# $NetBSD: Makefile,v 1.2 2014/02/26 18:20:11 wiedi Exp $
#

DISTNAME=	scrypt-1.1.6
CATEGORIES=	security
MASTER_SITES=	https://www.tarsnap.com/scrypt/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	https://www.tarsnap.com/scrypt/
COMMENT=	The scrypt encryption utility
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
