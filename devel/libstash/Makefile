# $NetBSD: Makefile,v 1.5 2005/12/05 20:50:05 rillig Exp $
#

DISTNAME=	libstash_s19990912a
PKGNAME=	libstash-19990912
CATEGORIES=	devel
MASTER_SITES=	http://www.canonware.com/sqrl/download/snapshots/199909/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.sqrl.org/sqrl/
COMMENT=	Collection of programming support routines and useful algorithms

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--without-pthreads
CONFIGURE_ARGS+=	--disable-shared

.include "../../mk/bsd.pkg.mk"
