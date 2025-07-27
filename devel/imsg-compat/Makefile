# $NetBSD: Makefile,v 1.6 2025/07/27 14:37:37 vins Exp $

DISTNAME=	imsg-compat-8.0.0
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=bsd-ac/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://github.com/bsd-ac/imsg-compat/
COMMENT=	Portable version of OpenBSD's imsg interface
LICENSE=	isc

USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libimsg.pc.in

CFLAGS.SunOS+=	-D_XOPEN_SOURCE=600	# CMSG_ functions
CFLAGS.SunOS+=	-D__EXTENSIONS__	# recallocarray()
LDFLAGS.SunOS+=	-lxnet

.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
