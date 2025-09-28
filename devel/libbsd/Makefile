# $NetBSD: Makefile,v 1.11 2025/09/28 06:18:34 vins Exp $

DISTNAME=	libbsd-0.12.2
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://libbsd.freedesktop.org/releases/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://libbsd.freedesktop.org/
COMMENT=	Compatibility library for BSD functions under other systems
LICENSE=	modified-bsd AND 2-clause-bsd AND isc AND mit AND beer-ware

# On these platforms, patch configure.ac to include -
# only the required bits.
#NOT_FOR_PLATFORM+=	FreeBSD-*-* OpenBSD-*-* DragonFly-*

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
