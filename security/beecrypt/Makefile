# $NetBSD: Makefile,v 1.14 2023/08/14 05:25:08 wiz Exp $

DISTNAME=	beecrypt-4.1.1
PKGREVISION=	1
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
