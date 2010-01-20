# $NetBSD: Makefile,v 1.5 2010/01/20 14:06:55 wiz Exp $

DISTNAME=	libev-3.9
CATEGORIES=	devel
MASTER_SITES=	http://dist.schmorp.de/libev/

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://software.schmorp.de/pkg/libev.html
COMMENT=	Full-featured and high-performance event loop
LICENSE=	modified-bsd OR gnu-gpl-v2 # NOTE: 2-clause BSD

CONFLICTS+=	libevent-[0-9]*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
#TEST_TARGET=	verify

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
