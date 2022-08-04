# $NetBSD: Makefile,v 1.7 2022/08/04 15:29:00 nia Exp $

DISTNAME=	wayland-protocols-1.26
CATEGORIES=	devel
MASTER_SITES=	https://wayland.freedesktop.org/releases/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wayland.freedesktop.org/
COMMENT=	Additional wayland functionality
LICENSE=	mit

USE_TOOLS+=		pkg-config

MESON_ARGS+=		-Dtests=false

PKGCONFIG_OVERRIDE+=	wayland-protocols.pc.in

.include "../../devel/meson/build.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
