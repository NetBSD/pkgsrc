# $NetBSD: Makefile,v 1.30 2026/11/26 22:15:43 wiz Exp $

DISTNAME=	librelp-1.2.16
PKGREVISION=	20
CATEGORIES=	devel
MASTER_SITES=	http://download.rsyslog.com/librelp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rsyslog/librelp
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

TEST_TARGET=	check

.include "../../security/gnutls/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
