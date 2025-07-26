# $NetBSD: Makefile,v 1.3 2025/07/26 09:08:53 vins Exp $

DISTNAME=	imsg-compat-8.0.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=bsd-ac/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://github.com/bsd-ac/imsg-compat/
COMMENT=	Portable version of OpenBSD's imsg interface
LICENSE=	isc

PKGCONFIG_OVERRIDE+=	libimsg.pc.in

CFLAGS.SunOS+=	-D_XOPEN_SOURCE=600	# CMSG_ functions
LDFLAGS.SunOS+=	-lxnet

.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
