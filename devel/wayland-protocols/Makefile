# $NetBSD: Makefile,v 1.9 2023/01/02 22:17:58 ryoon Exp $

DISTNAME=	wayland-protocols-1.26
PKGREVISION=	2
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
