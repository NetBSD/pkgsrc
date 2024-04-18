# $NetBSD: Makefile,v 1.13 2024/04/18 09:21:33 wiz Exp $

DISTNAME=	wayland-protocols-1.35
CATEGORIES=	devel
MASTER_SITES=	https://gitlab.freedesktop.org/wayland/wayland-protocols/-/releases/${PKGVERSION_NOREV}/downloads/
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
