# $NetBSD: Makefile,v 1.7 2010/12/02 15:47:12 wiz Exp $

DISTNAME=	libev-4.01
CATEGORIES=	devel
MASTER_SITES=	http://dist.schmorp.de/libev/

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://software.schmorp.de/pkg/libev.html
COMMENT=	Full-featured and high-performance event loop
LICENSE=	2-clause-bsd OR gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
#TEST_TARGET=	verify

CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/ev
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/ev

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
