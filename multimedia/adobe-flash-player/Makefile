# $NetBSD: Makefile,v 1.48 2020/06/10 10:26:29 tsutsui Exp $

FLASH_VERSION=		32.0.0.387
DISTNAME=		flash_player_npapi_linux.${FLASH_ARCH}
PKGNAME=		adobe-flash-player-${FLASH_VERSION}
DIST_SUBDIR=		${PKGNAME_NOREV}
CATEGORIES=		multimedia www
MASTER_SITES=		https://fpdownload.macromedia.com/get/flashplayer/pdc/${FLASH_VERSION}/

MAINTAINER=		tsutsui@NetBSD.org
HOMEPAGE=		https://www.adobe.com/products/flashplayer.html
COMMENT=		Adobe Flash Player Browser NPAPI plugin
LICENSE=		flash-license

RESTRICTED=		Redistribution not permitted
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

WRKSRC=			${WRKDIR}
BUILD_DIRS=		# empty

EMUL_PLATFORMS=		linux-i386 linux-x86_64
EMUL_MODULES.linux=	gtk2 x11 glx krb5 alsa curl nss nspr
# flashplayer 24 still supports OpenSUSE 11.3, but NetBSD 6.x uses 12.1
# by default so I won't bother to test with 11.3.
EMUL_REQD=		suse>=12.1

.include "../../mk/bsd.prefs.mk"

.if ${EMUL_PLATFORM} == "linux-i386"
FLASH_ARCH=		i386
.elif ${EMUL_PLATFORM} == "linux-x86_64"
FLASH_ARCH=		x86_64
.endif

CONFLICTS=		adobe-flash-plugin-[0-9]*

NS_PLUGINS_DIR=		${PREFIX}/lib/netscape/plugins

.include "options.mk"

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${NS_PLUGINS_DIR}
	${INSTALL_DATA} ${WRKSRC}/libflashplayer.so \
		${DESTDIR}${NS_PLUGINS_DIR}

.include "../../mk/bsd.pkg.mk"
