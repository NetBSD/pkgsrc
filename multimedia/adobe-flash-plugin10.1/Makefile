# $NetBSD: Makefile,v 1.14 2011/11/03 18:16:51 abs Exp $

DISTNAME=		flash-plugin-${FLASH_VERSION}-release.i386
PKGNAME=		adobe-${DISTNAME:C/-release.*//}
PKGREVISION=		5
CATEGORIES=		multimedia www
MASTER_SITES=		http://fpdownload.macromedia.com/get/flashplayer/current/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.adobe.com/products/flashplayer.html
COMMENT=		Adobe Flash Player Browser plugin
LICENSE=		flash-license

RESTRICTED=		Redistribution not permitted
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

PKG_DESTDIR_SUPPORT=	user-destdir

NOT_FOR_PLATFORM=	NetBSD-[0-4]*-* NetBSD-5.[0-9].*-*

WRKSRC=			${WRKDIR}
BUILD_DIRS=		# empty
EXTRACT_SUFX=		.rpm

CRYPTO=			yes

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	gtk2 x11 krb5 alsa curl
EMUL_REQD=		suse>=11.3

FLASH_VERSION=		10.3.183.7

CONFLICTS=		ns-flash-[0-9]*

NS_PLUGINS_DIR=		${PREFIX}/lib/netscape/plugins

.include "options.mk"

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${NS_PLUGINS_DIR}
	${INSTALL_DATA} ${WRKSRC}/usr/lib/flash-plugin/libflashplayer.so \
		${DESTDIR}${NS_PLUGINS_DIR}

.include "../../mk/bsd.pkg.mk"
