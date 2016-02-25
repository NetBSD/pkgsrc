# $NetBSD: Makefile,v 1.7 2016/02/25 08:27:03 jperkin Exp $
#

DISTNAME=	libmowgli-0.7.1
CATEGORIES=	devel
MASTER_SITES=	http://distfiles.atheme.org/ \
		http://mirror.billymays.us/libmowgli/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://www.atheme.org/projects/mowgli
COMMENT=	Development framework for C (like GLib)

PREV_PKGPATH=	devel/mowgli

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libmowgli.pc.in

# Explicitly disable epoll on illumos, provided for Linux compat only.
CONFIGURE_ENV.SunOS+=	ac_cv_func_epoll_ctl=no

.include "../../mk/bsd.pkg.mk"
