# $NetBSD: Makefile,v 1.13 2003/08/29 00:56:25 dan Exp $

DISTNAME=	libmcrypt-2.5.7
CATEGORIES=	security devel
MASTER_SITES=	ftp://mcrypt.hellug.gr/pub/mcrypt/libmcrypt/ \
		ftp://mcrypt.hellug.gr/pub/mcrypt/libmcrypt/old/ \
		http://mcrypt.hellug.gr/lib/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://mcrypt.hellug.gr/
COMMENT=	Crypto algorithms library

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

post-install:
	${RMDIR} ${PREFIX}/lib/libmcrypt

.include "../../mk/bsd.pkg.mk"
