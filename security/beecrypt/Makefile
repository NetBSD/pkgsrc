# $NetBSD: Makefile,v 1.1.1.1 2003/08/03 15:47:42 jmmv Exp $
#

DISTNAME=	beecrypt-2.1.0
CATEGORIES=	security
MASTER_SITES=	http://www.virtualunlimited.com/download/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.virtualunlimited.com/products/beecrypt/
COMMENT=	Multipurpose cryptographic library

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ARGS+=	--without-javaglue

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
