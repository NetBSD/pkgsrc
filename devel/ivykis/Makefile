# $NetBSD: Makefile,v 1.2 2015/11/06 15:37:49 fhajny Exp $

DISTNAME=	ivykis-0.39
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
.endif

PKGCONFIG_OVERRIDE+=	misc/ivykis.pc.in

.include "../../mk/bsd.pkg.mk"
