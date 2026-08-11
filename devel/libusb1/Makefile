# $NetBSD: Makefile,v 1.38 2026/08/11 09:07:41 jperkin Exp $

DISTNAME=	libusb-1.0.30
PKGNAME=	${DISTNAME:S/libusb/libusb1/}
PKGREVISION=	1
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

USE_CC_FEATURES=	c11

USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake autoreconf pkg-config
GNU_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"
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
