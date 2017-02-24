# $NetBSD: Makefile,v 1.66 2017/02/24 19:08:30 tsutsui Exp $

DISTNAME=		fp_${FLASH_VERSION}_archive
PKGNAME=		adobe-flash-plugin-${FLASH_VERSION}
PKGREVISION=		1
CATEGORIES=		multimedia www
MASTER_SITES=		http://fpdownload.macromedia.com/pub/flashplayer/installers/archive/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.adobe.com/products/flashplayer.html
COMMENT=		Adobe Flash Player Browser plugin
LICENSE=		flash-license

RESTRICTED=		Redistribution not permitted
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

# On NetBSD, requires sufficiently new compat_linux.
NOT_FOR_PLATFORM=	NetBSD-[0-4]*-* NetBSD-5.[0-9].*-*

WRKSRC=			${WRKDIR}
BUILD_DIRS=		# empty
EXTRACT_SUFX=		.zip
USE_TOOLS+=		tar

CRYPTO=			yes

EMUL_PLATFORMS=		linux-i386 linux-x86_64
EMUL_MODULES.linux=	gtk2 x11 krb5 alsa curl nss nspr
EMUL_REQD=		suse>=11.3

FLASH_VERSION=		11.2.202.644
FP_ARCHIVE_VERSION=	11_2r202_644
FP_ARCHIVE_DIR_PREFIX=	11_2_r202_644

.include "../../mk/bsd.prefs.mk"

.if ${EMUL_PLATFORM} == "linux-i386"
FLASH_ARCH=		i386
FP_ARCHIVE_DIR_SUFFIX=	32bit
.elif ${EMUL_PLATFORM} == "linux-x86_64"
FLASH_ARCH=		x86_64
FP_ARCHIVE_DIR_SUFFIX=	64bit
.endif

FP_ARCHIVE_DIR=		${FP_ARCHIVE_DIR_PREFIX}_${FP_ARCHIVE_DIR_SUFFIX}
FP_ARCHIVE=		flashplayer${FP_ARCHIVE_VERSION}_linux.${FLASH_ARCH}.tar.gz

CONFLICTS=		ns-flash-[0-9]* adobe-flash-player-[0-9]*

NS_PLUGINS_DIR=		${PREFIX}/lib/netscape/plugins

.include "options.mk"

post-extract:
	cd ${WRKDIR} && tar -zxf ${FP_ARCHIVE_DIR}/${FP_ARCHIVE}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${NS_PLUGINS_DIR}
	${INSTALL_DATA} ${WRKSRC}/libflashplayer.so \
		${DESTDIR}${NS_PLUGINS_DIR}

.include "../../mk/bsd.pkg.mk"
