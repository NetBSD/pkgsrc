# $NetBSD: Makefile,v 1.5 2020/03/15 16:05:53 nia Exp $

DISTNAME=	wayland-protocols-1.20
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
