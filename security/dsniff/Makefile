# $NetBSD: Makefile,v 1.3 2000/08/11 08:29:39 jlam Exp $
# $OpenBSD: Makefile,v 1.13 2000/06/19 18:38:55 dugsong Exp $

DISTNAME=	dsniff-2.2
CATEGORIES=	security
MASTER_SITES+=	http://www.monkey.org/~dugsong/dsniff/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.monkey.org/~dugsong/dsniff/

# These libraries are static, thus they aren't necessary at run-time,
# only at compile-time.
#
BUILD_DEPENDS+=	libnet-*:../../net/libnet
BUILD_DEPENDS+=	libnids-*:../../net/libnids

GNU_CONFIGURE=	yes
USE_X11=	yes

.include "../../mk/bsd.pkg.mk"
