# $NetBSD: Makefile,v 1.1.1.1 2000/11/10 11:34:44 itojun Exp $

DISTNAME=	mcrypt-2.5.5
CATEGORIES=	security devel
MASTER_SITES=	http://mcrypt.hellug.gr/mcrypt/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://mcrypt.hellug.gr/

DEPENDS+=	libmcrypt-*:../../security/libmcrypt
DEPENDS+=	mhash-*:../../security/mhash

USE_LIBTOOL=	yes
USE_LIBINTL=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"

.include "../../mk/bsd.pkg.mk"
