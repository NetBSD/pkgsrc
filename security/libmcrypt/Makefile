# $NetBSD: Makefile,v 1.6.2.2 2002/07/01 17:45:09 jlam Exp $

DISTNAME=	libmcrypt-2.4.22
CATEGORIES=	security devel
MASTER_SITES=	ftp://mcrypt.hellug.gr/pub/mcrypt/libmcrypt/ \
		ftp://mcrypt.hellug.gr/pub/mcrypt/libmcrypt/old/ \
		http://mcrypt.hellug.gr/lib/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://mcrypt.hellug.gr/
COMMENT=	crypto algorithms library

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

post-extract:
	${RM} -rf ${WRKSRC}/libltdl

.include "../../devel/libtool/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
