# $NetBSD: Makefile,v 1.13 2015/10/17 09:53:31 adam Exp $

DISTNAME=	libev-4.20
CATEGORIES=	devel
MASTER_SITES=	http://dist.schmorp.de/libev/

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://software.schmorp.de/pkg/libev.html
COMMENT=	Full-featured and high-performance event loop
LICENSE=	2-clause-bsd OR gnu-gpl-v2

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
GNU_CONFIGURE_LIBSUBDIR=ev
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/ev
# Explicitly disable inotify on SunOS, assumes Linux statfs.
CONFIGURE_ENV.SunOS+=	ac_cv_header_sys_inotify_h=no
#TEST_TARGET=	verify

OPSYSVARS+=	CONFIGURE_ENV

#.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
