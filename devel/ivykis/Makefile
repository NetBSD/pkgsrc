# $NetBSD: Makefile,v 1.1 2015/11/01 13:38:52 fhajny Exp $

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

.if ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	ac_cv_func_inotify_init=no
.endif

PKGCONFIG_OVERRIDE+=	misc/ivykis.pc.in

.include "../../mk/bsd.pkg.mk"
