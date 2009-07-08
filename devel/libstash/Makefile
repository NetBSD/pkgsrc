# $NetBSD: Makefile,v 1.6 2009/07/08 16:09:00 joerg Exp $
#

DISTNAME=	libstash_s19990912a
PKGNAME=	libstash-19990912
CATEGORIES=	devel
MASTER_SITES=	http://www.canonware.com/sqrl/download/snapshots/199909/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.sqrl.org/sqrl/
COMMENT=	Collection of programming support routines and useful algorithms

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--without-pthreads
CONFIGURE_ARGS+=	--disable-shared

.include "../../mk/bsd.pkg.mk"
