# $NetBSD: Makefile,v 1.3 2020/01/05 22:09:52 nia Exp $

DISTNAME=	wayland-protocols-1.18
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
