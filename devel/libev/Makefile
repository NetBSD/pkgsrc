# $NetBSD: Makefile,v 1.12 2015/02/02 10:33:13 jperkin Exp $

DISTNAME=	libev-4.15
CATEGORIES=	devel
MASTER_SITES=	http://dist.schmorp.de/libev/

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://software.schmorp.de/pkg/libev.html
COMMENT=	Full-featured and high-performance event loop
LICENSE=	2-clause-bsd OR gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
#TEST_TARGET=	verify

GNU_CONFIGURE_LIBSUBDIR=ev
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/ev

OPSYSVARS+=	CONFIGURE_ENV

# Explicitly disable inotify on SunOS, assumes Linux statfs.
CONFIGURE_ENV.SunOS+=	ac_cv_header_sys_inotify_h=no

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
