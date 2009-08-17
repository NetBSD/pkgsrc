# $NetBSD: Makefile,v 1.3 2009/08/17 11:08:30 drochner Exp $

DISTNAME=	libev-3.7
PKGREVISION=	1
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
