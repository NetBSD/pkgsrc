# $NetBSD: Makefile,v 1.20 2019/11/03 10:39:16 rillig Exp $

DISTNAME=	libev-4.27
CATEGORIES=	devel
MASTER_SITES=	http://dist.schmorp.de/libev/

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://software.schmorp.de/pkg/libev.html
COMMENT=	Full-featured and high-performance event loop
LICENSE=	2-clause-bsd OR gnu-gpl-v2

USE_LIBTOOL=			yes
GNU_CONFIGURE=			yes
GNU_CONFIGURE_LIBSUBDIR=	ev
CONFIGURE_ARGS+=		--includedir=${PREFIX}/include/ev
# Explicitly disable inotify on SunOS, assumes Linux statfs.
CONFIGURE_ENV.SunOS+=		ac_cv_header_sys_inotify_h=no
CONFIGURE_ENV.SunOS+=		ac_cv_header_sys_epoll_h=no

.include "../../mk/bsd.pkg.mk"
