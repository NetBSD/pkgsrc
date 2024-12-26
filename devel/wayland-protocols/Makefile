# $NetBSD: Makefile,v 1.15 2024/12/26 11:00:52 wiz Exp $

DISTNAME=	wayland-protocols-1.39
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
