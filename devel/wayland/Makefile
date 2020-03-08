# $NetBSD: Makefile,v 1.7 2020/03/08 16:42:26 bsiegert Exp $

DISTNAME=	wayland-1.17.0
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	https://wayland.freedesktop.org/releases/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://wayland.freedesktop.org/
COMMENT=	Display server protocol - development libraries
LICENSE=	mit

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

USE_TOOLS+=	autoconf automake autoreconf
USE_TOOLS+=	gmake pkg-config

USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--disable-documentation

PKGCONFIG_OVERRIDE+=	src/wayland-client.pc.in
PKGCONFIG_OVERRIDE+=	src/wayland-cursor.pc.in
PKGCONFIG_OVERRIDE+=	src/wayland-scanner.pc.in
PKGCONFIG_OVERRIDE+=	src/wayland-server.pc.in

pre-configure:
	# https://lists.freedesktop.org/archives/wayland-devel/2019-February/040024.html
	${CP} ${FILESDIR}/event-loop-kqueue.c ${WRKSRC}/src
	cd ${WRKSRC} && autoreconf -fvi

.include "platform.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
