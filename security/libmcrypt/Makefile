# $NetBSD: Makefile,v 1.18 2006/03/04 21:30:34 jlam Exp $

DISTNAME=	libmcrypt-2.5.7
PKGREVISION=	1
CATEGORIES=	security devel
MASTER_SITES=	ftp://mcrypt.hellug.gr/pub/mcrypt/libmcrypt/ \
		ftp://mcrypt.hellug.gr/pub/mcrypt/libmcrypt/old/ \
		http://mcrypt.hellug.gr/lib/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mcrypt.hellug.gr/
COMMENT=	Crypto algorithms library

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

post-install:
	${RMDIR} ${PREFIX}/lib/libmcrypt

.include "../../mk/bsd.pkg.mk"
