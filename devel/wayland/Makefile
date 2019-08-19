# $NetBSD: Makefile,v 1.2 2019/08/19 12:50:23 nia Exp $

DISTNAME=	wayland-1.17.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://wayland.freedesktop.org/releases/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wayland.freedesktop.org/
COMMENT=	Display server protocol - development libraries
LICENSE=	mit

USE_TOOLS+=		autoconf automake autoreconf gmake pkg-config
USE_LANGUAGES+=		c c++
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
CONFIGURE_ARGS+=	--disable-documentation

PKGCONFIG_OVERRIDE+=	src/wayland-client.pc.in
PKGCONFIG_OVERRIDE+=	src/wayland-cursor.pc.in
PKGCONFIG_OVERRIDE+=	src/wayland-scanner.pc.in
PKGCONFIG_OVERRIDE+=	src/wayland-server.pc.in

pre-configure:
	# https://lists.freedesktop.org/archives/wayland-devel/2019-February/040024.html
	${CP} ${FILESDIR}/event-loop-kqueue.c ${WRKSRC}/src
	cd ${WRKSRC} && autoreconf -fvi

.include "../../devel/libffi/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
