# $NetBSD: Makefile,v 1.7 2023/08/14 05:25:01 wiz Exp $

DISTNAME=	libslirp-4.7.0
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	https://gitlab.freedesktop.org/slirp/libslirp/uploads/60113f60cfd6abe2c16dde9f6c81b631/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.freedesktop.org/slirp/libslirp
COMMENT=	User-mode networking library
LICENSE=	modified-bsd

USE_TOOLS+=	pkg-config

PYTHON_FOR_BUILD_ONLY=	tool

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		output/meson-private/slirp.pc

LDFLAGS.SunOS+=		-lsocket

.include "../../devel/meson/build.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
