# $NetBSD: Makefile,v 1.16 2004/10/03 00:18:10 tv Exp $

DISTNAME=	libmcrypt-2.5.7
PKGREVISION=	1
CATEGORIES=	security devel
MASTER_SITES=	ftp://mcrypt.hellug.gr/pub/mcrypt/libmcrypt/ \
		ftp://mcrypt.hellug.gr/pub/mcrypt/libmcrypt/old/ \
		http://mcrypt.hellug.gr/lib/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://mcrypt.hellug.gr/
COMMENT=	Crypto algorithms library

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

post-install:
	${RMDIR} ${PREFIX}/lib/libmcrypt

.include "../../mk/bsd.pkg.mk"
