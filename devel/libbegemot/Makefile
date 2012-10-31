# $NetBSD: Makefile,v 1.15 2012/10/31 11:17:10 asau Exp $
#

DISTNAME=	libbegemot-1.11
CATEGORIES=	devel
MASTER_SITES=	http://people.freebsd.org/~harti/libbegemot/

MAINTAINER=	packages@grumpf.hope-2000.org
COMMENT=	Base development library, contains useful routines

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

CFLAGS.SunOS=	-Du_int64_t=uint64_t

.include "../../mk/bsd.pkg.mk"
