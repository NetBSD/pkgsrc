# $NetBSD: Makefile,v 1.12 2003/06/02 01:17:19 jschauma Exp $
# $OpenBSD: Makefile,v 1.13 2000/06/19 18:38:55 dugsong Exp $

DISTNAME=	dsniff-2.3
CATEGORIES=	security
MASTER_SITES+=	http://monkey.org/~dugsong/dsniff/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://monkey.org/~dugsong/dsniff/
COMMENT=	password sniffer

DEPENDS+=	libnet-[0-9]*:../../devel/libnet
# libnids provides static library only, thus it isn't necessary at run-time,
# only at compile-time.
#
BUILD_DEPENDS+=	libnids-1.14:../../net/libnids

GNU_CONFIGURE=	yes
USE_X11=	yes

.include "../../mk/bsd.pkg.mk"
