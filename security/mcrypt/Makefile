# $NetBSD: Makefile,v 1.3 2001/06/11 06:34:48 jlam Exp $

DISTNAME=	mcrypt-2.5.5
CATEGORIES=	security devel
MASTER_SITES=	http://mcrypt.hellug.gr/mcrypt/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://mcrypt.hellug.gr/
COMMENT=	replacement to crypt(1), supports bunch of algorithms

DEPENDS+=	libmcrypt-*:../../security/libmcrypt
DEPENDS+=	mhash-*:../../security/mhash

USE_LIBTOOL=	yes
USE_LIBINTL=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include

.include "../../mk/bsd.pkg.mk"
