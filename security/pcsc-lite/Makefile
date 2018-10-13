# $NetBSD: Makefile,v 1.29 2018/10/13 10:52:35 mlelstv Exp $

DISTNAME=	pcsc-lite-1.8.24
CATEGORIES=	security
# Note that the MASTER_SITES URL is not stable with version changes,
# and one can end up with an old version if DISTNAME is changed but
# not the magic number in MASTER_SITES.
# https://alioth.debian.org/frs/?group_id=30105&release_id=2031#pcsclite-_1.8.18-title-content
MASTER_SITES=	https://pcsclite.apdu.fr/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pcsclite.apdu.fr/

COMMENT=	Middleware to access a smart card using SCard API (PC/SC)
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=    spy
#REPLACE_PYTHON=		src/spy/pcsc-spy
#.include "../../lang/python/application.mk"

CONFIGURE_ARGS+=	--sharedstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--enable-confdir=${PKG_SYSCONFDIR:Q}/reader.conf.d
CONFIGURE_ARGS+=	--enable-ipcdir=${VARBASE}/pcsc-lite
CONFIGURE_ARGS+=	--enable-usbdropdir=${PREFIX}/lib/pcsc-lite/drivers
CONFIGURE_ARGS+=	--disable-libudev
CONFIGURE_ARGS+=	--disable-libsystemd
MAKE_DIRS+=		${VARBASE}/pcsc-lite
MAKE_DIRS+=		${PREFIX}/lib/pcsc-lite
MAKE_DIRS+=		${PREFIX}/lib/pcsc-lite/drivers
MAKE_DIRS+=		${PKG_SYSCONFDIR}/reader.conf.d

EGDIR=			${PREFIX}/share/examples/pcsc-lite

PKGCONFIG_OVERRIDE+=	src/libpcsclite.pc.in

BUILD_DEFS+=		VARBASE
RCD_SCRIPTS=		pcscd

.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
