# $NetBSD: Makefile,v 1.2 2000/08/11 08:14:16 itojun Exp $
# $OpenBSD: Makefile,v 1.13 2000/06/19 18:38:55 dugsong Exp $

DISTNAME=	dsniff-2.2
CATEGORIES=	security
MASTER_SITES+=	http://www.monkey.org/~dugsong/dsniff/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.monkey.org/~dugsong/dsniff/

DEPENDS=	libnet-*:../../net/libnet \
		libnids-*:../../net/libnids

GNU_CONFIGURE=	yes
USE_X11=	yes

.include "../../mk/bsd.pkg.mk"
