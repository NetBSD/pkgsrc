# $NetBSD: Makefile,v 1.6 2004/12/05 09:02:11 jmmv Exp $

DISTNAME=	beecrypt-4.1.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=beecrypt/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.virtualunlimited.com/products/beecrypt/
COMMENT=	Multipurpose cryptographic library

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES

CONFIGURE_ARGS+=	--without-javaglue

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
