# $NetBSD: Makefile,v 1.3 2016/01/05 10:47:52 fhajny Exp $

DISTNAME=	ivykis-0.39
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=buytenh/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/buytenh/ivykis/
COMMENT=	Asynchronous I/O readiness notification library
LICENSE=	gnu-lgpl-v3

GITHUB_TAG=	v${PKGVERSION_NOREV}

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

.include "../../mk/bsd.prefs.mk"

# Disable inotify checks on non-Linux platforms
.if ${OPSYS} != "Linux"
CONFIGURE_ARGS+=	ac_cv_func_inotify_init=no
CONFIGURE_ARGS+=	ac_cv_func_epoll_create=no
.endif

PKGCONFIG_OVERRIDE+=	misc/ivykis.pc.in

.include "../../mk/bsd.pkg.mk"
