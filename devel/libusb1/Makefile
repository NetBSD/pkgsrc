# $NetBSD: Makefile,v 1.23 2020/04/03 20:05:41 nia Exp $

DISTNAME=	libusb-1.0.23
PKGNAME=	${DISTNAME:S/libusb/libusb1/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=libusb/}
GITHUB_PROJECT=	libusb
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://libusb.info/
COMMENT=	USB Access Library (version 1)
LICENSE=	gnu-lgpl-v2.1

# Works on Dragonfly but explicitly not wanted by DragonFly upstream;
# see PR 47042.
NOT_FOR_PLATFORM=	DragonFly-*-*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
MAKE_JOBS_SAFE=	no

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
# Uses undefined behaviour
BUILDLINK_TRANSFORM+=	opt:-O2:-O1
CFLAGS+=		-fno-strict-aliasing
.endif

PKGCONFIG_OVERRIDE+=	libusb-1.0.pc.in

# systemd dependency
CONFIGURE_ARGS.Linux+=	--disable-udev

CONFIGURE_ARGS+=	--enable-tests-build
#CONFIGURE_ARGS+=	--enable-examples-build

LDFLAGS.SunOS+=		-lcmdutils # list_create(9F)

CONFLICTS=	libusbx-[0-9]*

do-test:
	cd ${WRKSRC}/tests && ./stress

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
