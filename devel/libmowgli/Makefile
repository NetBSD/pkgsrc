# $NetBSD: Makefile,v 1.10 2019/11/22 00:12:34 nia Exp $

DISTNAME=	libmowgli-2.1.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=atheme/}
GITHUB_PROJECT=	libmowgli-2
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	https://github.com/atheme/libmowgli-2
COMMENT=	Development framework for C (like GLib)
LICENSE=	isc

PREV_PKGPATH=	devel/mowgli

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config

CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}

PKGCONFIG_OVERRIDE+=	libmowgli-2.pc.in

# Explicitly disable epoll on illumos, provided for Linux compat only.
CONFIGURE_ENV.SunOS+=	ac_cv_func_epoll_ctl=no

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
