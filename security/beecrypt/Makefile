# $NetBSD: Makefile,v 1.8 2006/03/04 21:30:33 jlam Exp $

DISTNAME=	beecrypt-4.1.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=beecrypt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.virtualunlimited.com/products/beecrypt/
COMMENT=	Multipurpose cryptographic library

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

CONFIGURE_ARGS+=	--without-javaglue

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
