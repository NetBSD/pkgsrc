# $NetBSD: Makefile,v 1.3 2004/02/14 17:21:50 jlam Exp $
#

DISTNAME=	beecrypt-3.0.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=beecrypt/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.virtualunlimited.com/products/beecrypt/
COMMENT=	Multipurpose cryptographic library

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES

CONFIGURE_ARGS+=	--without-javaglue

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
