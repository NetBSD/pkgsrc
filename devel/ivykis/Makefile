# $NetBSD: Makefile,v 1.10 2018/01/12 14:33:14 fhajny Exp $

DISTNAME=	ivykis-0.42.2
PKGREVISION=	1
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

PTHREAD_AUTO_VARS=	yes

PKGCONFIG_OVERRIDE+=	misc/ivykis.pc.in

TEST_TARGET=		check

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
