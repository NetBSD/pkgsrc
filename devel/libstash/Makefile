# $NetBSD: Makefile,v 1.11 2023/12/29 15:47:01 zafer Exp $

DISTNAME=	libstash_s19990912a
PKGNAME=	libstash-19990912
CATEGORIES=	devel
MASTER_SITES=	#

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.grc.com/sqrl/sqrl.htm
COMMENT=	Collection of programming support routines and useful algorithms

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-pthreads
CONFIGURE_ARGS+=	--disable-shared

MAKE_FILE=	Makefile.bsd

.include "../../mk/bsd.pkg.mk"
