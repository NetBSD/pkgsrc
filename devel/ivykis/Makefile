# $NetBSD: Makefile,v 1.4 2016/11/04 10:47:36 fhajny Exp $

DISTNAME=	ivykis-0.40
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
