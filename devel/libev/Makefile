# $NetBSD: Makefile,v 1.4.4.1 2010/01/31 14:04:37 tron Exp $

DISTNAME=	libev-3.8
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://dist.schmorp.de/libev/

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://software.schmorp.de/pkg/libev.html
COMMENT=	Full-featured and high-performance event loop
LICENSE=	modified-bsd OR gnu-gpl-v2 # NOTE: 2-clause BSD

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
#TEST_TARGET=	verify

CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/ev
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/ev

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
