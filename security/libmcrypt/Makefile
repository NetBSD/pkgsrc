# $NetBSD: Makefile,v 1.10 2003/06/02 01:17:16 jschauma Exp $

DISTNAME=	libmcrypt-2.5.6
CATEGORIES=	security devel
MASTER_SITES=	ftp://mcrypt.hellug.gr/pub/mcrypt/libmcrypt/ \
		ftp://mcrypt.hellug.gr/pub/mcrypt/libmcrypt/old/ \
		http://mcrypt.hellug.gr/lib/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://mcrypt.hellug.gr/
COMMENT=	crypto algorithms library

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

post-install:
	${RMDIR} ${PREFIX}/lib/libmcrypt

.include "../../mk/bsd.pkg.mk"
