# $NetBSD: Makefile,v 1.9 2017/09/25 16:11:54 wiedi Exp $

DISTNAME=	libstash_s19990912a
PKGNAME=	libstash-19990912
CATEGORIES=	devel
MASTER_SITES=	http://www.canonware.com/sqrl/download/snapshots/199909/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.sqrl.org/sqrl/
COMMENT=	Collection of programming support routines and useful algorithms

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--without-pthreads
CONFIGURE_ARGS+=	--disable-shared

MAKE_FILE=	Makefile.bsd

.include "../../mk/bsd.pkg.mk"
