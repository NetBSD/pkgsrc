# $NetBSD: Makefile,v 1.4 2004/04/12 20:50:27 snj Exp $

DISTNAME=	beecrypt-3.0.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=beecrypt/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.virtualunlimited.com/products/beecrypt/
COMMENT=	Multipurpose cryptographic library

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES

CONFIGURE_ARGS+=	--without-javaglue

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
