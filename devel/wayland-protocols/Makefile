# $NetBSD: Makefile,v 1.4 2020/03/08 16:49:19 wiz Exp $

DISTNAME=	wayland-protocols-1.18
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://wayland.freedesktop.org/releases/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wayland.freedesktop.org/
COMMENT=	Additional wayland functionality
LICENSE=	mit

USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		YES

PKGCONFIG_OVERRIDE+=	wayland-protocols.pc.in

.include "../../devel/wayland/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
