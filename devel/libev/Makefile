# $NetBSD: Makefile,v 1.25 2023/07/31 09:13:58 tnn Exp $

DISTNAME=	libev-4.33
CATEGORIES=	devel
MASTER_SITES=	http://dist.schmorp.de/libev/Attic/

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://software.schmorp.de/pkg/libev.html
COMMENT=	Full-featured and high-performance event loop
LICENSE=	2-clause-bsd OR gnu-gpl-v2

USE_LIBTOOL=			yes
GNU_CONFIGURE=			yes
GNU_CONFIGURE_LIBSUBDIR=	ev
CONFIGURE_ARGS+=		--includedir=${PREFIX}/include/ev

# Explicitly disable inotify on SunOS, assumes Linux statfs.
CONFIGURE_ENV.SunOS+=	ac_cv_header_sys_inotify_h=no
CONFIGURE_ENV.SunOS+=	ac_cv_header_sys_epoll_h=no

# Disable epoll(2) on NetBSD since we prefer kqueue(2).
CONFIGURE_ARGS.NetBSD+=	ac_cv_header_sys_epoll_h=no

# Issues seen with multithreaded programs without _REENTRANT.
CPPFLAGS.SunOS+=	-D_REENTRANT

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MNetBSD-*-sparc)
# Prevent ev.c from using v9 memory barrier instructions
CPPFLAGS+=	-D__sparc_v8__=1
.endif

.include "../../mk/bsd.pkg.mk"
