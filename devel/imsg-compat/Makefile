# $NetBSD: Makefile,v 1.1 2025/07/25 20:53:51 vins Exp $

DISTNAME=	imsg-compat-8.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=bsd-ac/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://github.com/bsd-ac/imsg-compat/
COMMENT=	Portable OpenBSD imsg_* interface
LICENSE=	isc

PKGCONFIG_OVERRIDE+=	libimsg.pc.in

CFLAGS.SunOS+=	-D_XOPEN_SOURCE=600	# CMSG_ functions
LDFLAGS.SunOS+=	-lxnet

.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
