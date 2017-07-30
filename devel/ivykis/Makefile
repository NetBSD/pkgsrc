# $NetBSD: Makefile,v 1.7 2017/07/30 22:32:14 wiz Exp $

DISTNAME=	ivykis-0.42
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=buytenh/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/buytenh/ivykis/
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

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
