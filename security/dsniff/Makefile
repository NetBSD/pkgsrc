# $NetBSD: Makefile,v 1.6 2000/08/15 01:28:58 itojun Exp $
# $OpenBSD: Makefile,v 1.13 2000/06/19 18:38:55 dugsong Exp $

DISTNAME=	dsniff-2.2
CATEGORIES=	security
MASTER_SITES+=	http://www.monkey.org/~dugsong/dsniff/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.monkey.org/~dugsong/dsniff/

DEPENDS+=	libnet-*:../../devel/libnet
# libnids provides static library only, thus it isn't necessary at run-time,
# only at compile-time.
#
BUILD_DEPENDS+=	${LOCALBASE}/lib/libnids.a:../../net/libnids

GNU_CONFIGURE=	yes
USE_X11=	yes

.include "../../mk/bsd.pkg.mk"
