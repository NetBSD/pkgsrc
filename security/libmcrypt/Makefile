# $NetBSD: Makefile,v 1.5 2001/10/09 19:16:20 jlam Exp $

DISTNAME=	libmcrypt-2.4.17
CATEGORIES=	security devel
MASTER_SITES=	ftp://mcrypt.hellug.gr/pub/mcrypt/libmcrypt/ \
		ftp://mcrypt.hellug.gr/pub/mcrypt/libmcrypt/old/ \
		http://mcrypt.hellug.gr/lib/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://mcrypt.hellug.gr/
COMMENT=	crypto algorithms library

USE_BUILDLINK_ONLY=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

post-extract:
	${RM} -rf ${WRKSRC}/libltdl

.include "../../devel/libtool/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
