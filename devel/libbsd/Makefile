# $NetBSD: Makefile,v 1.5 2023/07/03 10:56:55 vins Exp $

DISTNAME=	libbsd-0.11.7
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://libbsd.freedesktop.org/releases/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://libbsd.freedesktop.org/
COMMENT=	Compatibility library for BSD functions under other systems
LICENSE=	original-bsd AND modified-bsd AND 2-clause-bsd
LICENSE+=	AND isc AND mit AND beer-ware

NOT_FOR_PLATFORM=	NetBSD-*-* FreeBSD-*-*
NOT_FOR_PLATFORM+=	OpenBSD-*-* DragonFly-*
BROKEN_ON_PLATFORM=	Darwin-*-* SunOS-*-*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config autoconf automake autoreconf

CFLAGS+=	-ffat-lto-objects

pre-configure:
	set -e; cd ${WRKSRC} && autoreconf -fiv

do-test:
	${RUN} cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${MAKE} check

PKGCONFIG_OVERRIDE+=	src/libbsd-ctor.pc.in
PKGCONFIG_OVERRIDE+=	src/libbsd-overlay.pc.in
PKGCONFIG_OVERRIDE+=	src/libbsd.pc.in

.include "../../devel/libmd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
