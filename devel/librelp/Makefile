# $NetBSD: Makefile,v 1.5 2018/04/17 22:29:31 wiz Exp $

DISTNAME=	librelp-1.2.15
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://download.rsyslog.com/librelp/

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://www.librelp.com/
COMMENT=	Reliable Event Logging Protocol core library
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

CONFIGURE_ARGS.SunOS+=	ac_cv_func_epoll_create1=no
CONFIGURE_ARGS.SunOS+=	ac_cv_func_epoll_create=no
CONFIGURE_ARGS.SunOS+=	ac_cv_header_sys_epoll_h=no
# Needed for obsolete NI_MAXHOST
CPPFLAGS.SunOS+=	-D__EXTENSIONS__

PKGCONFIG_OVERRIDE+=	relp.pc.in

.include "../../security/gnutls/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
