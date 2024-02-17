# $NetBSD: Makefile,v 1.34 2024/02/17 21:57:50 nia Exp $

DISTNAME=	libusb-1.0.27
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

USE_CC_FEATURES+=	c11

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake autoreconf
USE_TOOLS+=	pkg-config
MAKE_JOBS_SAFE=	no

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
# Uses undefined behaviour
BUILDLINK_TRANSFORM+=	opt:-O2:-O1
CFLAGS+=		-fno-strict-aliasing
.endif

# XXX should be only illumos
.if ${OPSYS} == "SunOS" && ${OPSYS_VERSION} >= 051100
LDFLAGS+=	-lnvpair
.endif

PKGCONFIG_OVERRIDE+=	libusb-1.0.pc.in

# systemd dependency
CONFIGURE_ARGS.Linux+=	--disable-udev

CONFIGURE_ARGS+=	--enable-tests-build
#CONFIGURE_ARGS+=	--enable-examples-build

LDFLAGS.SunOS+=		-lcmdutils # list_create(9F)

CONFLICTS=	libusbx-[0-9]*

pre-configure:
	cd ${WRKSRC} && autoreconf -fi

do-test:
	cd ${WRKSRC}/tests && ./stress

.include "options.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
