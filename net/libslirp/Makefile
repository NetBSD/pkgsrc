# $NetBSD: Makefile,v 1.11 2026/09/27 11:38:06 tnn Exp $

DISTNAME=	libslirp-4.9.3
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	https://gitlab.freedesktop.org/-/project/2767/uploads/bdcbb727b502f93d312e631cc0980055/
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
