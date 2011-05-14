# $NetBSD: Makefile,v 1.14 2011/05/14 20:21:19 hans Exp $
#

DISTNAME=	libbegemot-1.11
CATEGORIES=	devel
MASTER_SITES=	http://people.freebsd.org/~harti/libbegemot/

MAINTAINER=	packages@grumpf.hope-2000.org
COMMENT=	Base development library, contains useful routines

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

CFLAGS.SunOS=	-Du_int64_t=uint64_t

.include "../../mk/bsd.pkg.mk"
