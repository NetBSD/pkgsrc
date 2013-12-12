# $NetBSD: Makefile,v 1.22 2013/12/12 02:35:33 obache Exp $

DISTNAME=		flash-plugin-${FLASH_VERSION}-release.${FLASH_ARCH}
PKGNAME=		adobe-${DISTNAME:C/-release.*//}
CATEGORIES=		multimedia www
MASTER_SITES=		http://fpdownload.macromedia.com/get/flashplayer/pdc/${FLASH_VERSION}/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.adobe.com/products/flashplayer.html
COMMENT=		Adobe Flash Player Browser plugin
LICENSE=		flash-license

RESTRICTED=		Redistribution not permitted
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

NOT_FOR_PLATFORM=	NetBSD-[0-4]*-* NetBSD-5.[0-9].*-*

WRKSRC=			${WRKDIR}
BUILD_DIRS=		# empty
EXTRACT_SUFX=		.rpm

CRYPTO=			yes

# XXX At present, it seems www/nspluginwrapper does not support native x86_64
#     plugin. --2011-10-08 ryoon
EMUL_PLATFORMS=		linux-i386 #linux-x86_64
EMUL_MODULES.linux=	gtk2 x11 krb5 alsa curl nss nspr
EMUL_REQD=		suse>=11.3

FLASH_VERSION=		11.2.202.332

.include "../../mk/bsd.prefs.mk"

.if ${EMUL_PLATFORM} == "linux-i386"
FLASH_ARCH=		i386
FLASH_LIBDIR=		lib
.elif ${EMUL_PLATFORM} == "linux-x86_64"
FLASH_ARCH=		x86_64
FLASH_LIBDIR=		lib64
.endif

CONFLICTS=		ns-flash-[0-9]*

NS_PLUGINS_DIR=		${PREFIX}/lib/netscape/plugins

.include "options.mk"

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${NS_PLUGINS_DIR}
	${INSTALL_DATA} ${WRKSRC}/usr/${FLASH_LIBDIR}/flash-plugin/libflashplayer.so \
		${DESTDIR}${NS_PLUGINS_DIR}

.include "../../mk/bsd.pkg.mk"
