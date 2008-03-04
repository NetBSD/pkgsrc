# $NetBSD: Makefile,v 1.1.1.1 2008/03/04 11:29:08 shannonjr Exp $
#

DISTNAME=	pcsc-lite-1.4.99
CATEGORIES=	security
MASTER_SITES=	http://alioth.debian.org/frs/download.php/2257/

MAINTAINER=	shannonjr@NetBSD.org
HOMEPAGE=	http://alioth.debian.org/frs/download.php/2257/
COMMENT=	Middleware to access a smart card using SCard API (PC/SC).

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
MAKE_DIRS+=		${VARBASE}/pcsc-lite
MAKE_DIRS+=		${PREFIX}/lib/pcsc-lite
MAKE_DIRS+=		${PREFIX}/lib/pcsc-lite/drivers

EGDIR=			${PREFIX}/share/examples/pcsc-lite
CONF_FILES+=		${EGDIR}/reader.conf ${PKG_SYSCONFDIR}/reader.conf

PKGCONFIG_OVERRIDE+=	src/libpcsclite.pc.in

pre-configure:
	cd ${WRKSRC} && ${SH} bootstrap


post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/reader.conf ${EGDIR}

.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
