# $NetBSD: Makefile,v 1.6 2009/06/25 06:30:50 hasso Exp $
#

DISTNAME=	pcsc-lite-1.5.4
CATEGORIES=	security
MASTER_SITES=	http://alioth.debian.org/frs/download.php/3052/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	shannonjr@NetBSD.org
HOMEPAGE=	http://pcsclite.alioth.debian.org/
COMMENT=	Middleware to access a smart card using SCard API (PC/SC).

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_TOOLS+=	autoconf automake aclocal autoheader
AUTOMAKE_REQD=	1.10
AUTOCONF_REQD=	2.58
USE_LANGUAGES=	c c++

.include "options.mk"

CONFIGURE_ARGS+=	--sharedstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--enable-ipcdir=${VARBASE}/pcsc-lite
CONFIGURE_ARGS+=	--enable-usbdropdir=${PREFIX}/lib/pcsc-lite/drivers
CONFIGURE_ARGS+=	--disable-libhal
MAKE_DIRS+=		${VARBASE}/pcsc-lite
MAKE_DIRS+=		${PREFIX}/lib/pcsc-lite
MAKE_DIRS+=		${PREFIX}/lib/pcsc-lite/drivers

EGDIR=			${PREFIX}/share/examples/pcsc-lite
CONF_FILES+=		${EGDIR}/reader.conf ${PKG_SYSCONFDIR}/reader.conf

PKGCONFIG_OVERRIDE+=	src/libpcsclite.pc.in

INSTALLATION_DIRS=	${EGDIR}

pre-configure:
	cd ${WRKSRC} && ${SH} bootstrap


post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/reader.conf ${DESTDIR}${EGDIR}

.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
