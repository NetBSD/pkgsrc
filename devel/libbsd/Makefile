# $NetBSD: Makefile,v 1.7 2024/02/11 18:58:02 vins Exp $

DISTNAME=	libbsd-0.11.8
CATEGORIES=	devel
MASTER_SITES=	https://libbsd.freedesktop.org/releases/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://libbsd.freedesktop.org/
COMMENT=	Compatibility library for BSD functions under other systems
LICENSE=	modified-bsd AND 2-clause-bsd AND isc AND mit AND beer-ware

BROKEN_ON_PLATFORM=	Darwin-*-* SunOS-*-*
NOT_FOR_PLATFORM=	NetBSD-*-* FreeBSD-*-*
NOT_FOR_PLATFORM+=	OpenBSD-*-* DragonFly-*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config autoconf automake autoreconf

TEST_TARGET=	check

pre-configure:
	set -e; cd ${WRKSRC} && autoreconf -fiv

PKGCONFIG_OVERRIDE+=	src/libbsd-ctor.pc.in
PKGCONFIG_OVERRIDE+=	src/libbsd-overlay.pc.in
PKGCONFIG_OVERRIDE+=	src/libbsd.pc.in

.include "../../devel/libmd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
