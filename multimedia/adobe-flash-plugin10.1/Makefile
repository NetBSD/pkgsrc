# $NetBSD: Makefile,v 1.1.1.1 2011/02/08 18:47:03 ahoka Exp $

CATEGORIES=	multimedia www
#MASTER_SITES=	http://download.macromedia.com/pub/labs/flashplayer10/
MASTER_SITES=	http://fpdownload.macromedia.com/get/flashplayer/current/
#http://fpdownload.macromedia.com/get/flashplayer/current/install_flash_player_10_linux.tar.gz
#flash-plugin-10.1.102.65-release.i386.rpm
MASTER_SITES+=	ftp://www.dvo.ru/pub/Gentoo/distfiles/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.adobe.com/
COMMENT=		Adobe Flash Player Browser plugin
LICENSE=		flash-license

RESTRICTED=		Redistribution not permitted
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}
BUILD_DIRS=		# empty
DIST_SUBDIR=		flash/${FLASH_VERS}

CRYPTO=			yes

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	compat gtk2 x11 krb5
EMUL_REQD=		suse>=10.0

.include "../../mk/bsd.prefs.mk"

# Defaults so lintpkgsrc is happy
FLASH_VERS=		10.1.102.65
#FLASH_VERS=		10.0.0.525
.if ${EMUL_PLATFORM} == "linux-i386"
DISTUNAME=		linux
DISTNAME=		install_flash_player_10_${DISTUNAME}
WRKNAME=		install_flash_player_10_${DISTUNAME}
.endif

CONFLICTS=		ns-flash-[0-9]*
PKGNAME=		adobe-flash-plugin-${FLASH_VERS:S/r/./}

NS_PLUGINS_DIR=		${PREFIX}/lib/netscape/plugins

.include "options.mk"

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${NS_PLUGINS_DIR}
	${INSTALL_DATA} ${WRKSRC}/libflashplayer.so ${DESTDIR}${NS_PLUGINS_DIR}

.include "../../mk/bsd.pkg.mk"
