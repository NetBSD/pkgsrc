# $NetBSD: Makefile,v 1.15 2024/04/22 10:57:25 he Exp $

DISTNAME=	beecrypt-4.1.1
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=beecrypt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.virtualunlimited.com/products/beecrypt/
COMMENT=	Multipurpose cryptographic library

GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES

CONFIGURE_ARGS+=	--without-javaglue --without-python

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
