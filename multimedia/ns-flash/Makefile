# $NetBSD: Makefile,v 1.29.8.1 2008/11/07 13:12:13 rtr Exp $

CATEGORIES=		multimedia www
MASTER_SITES=		http://download.macromedia.com/pub/flashplayer/installers/current/9/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.flash.com/
COMMENT=		MacroMedia Flash Player Netscape plugin

# Must update communicator/navigator to at least 4.76nb1
CONFLICTS+=		communicator<=4.76nb1
CONFLICTS+=		navigator<=4.76nb1

LICENSE=		flash-license
RESTRICTED=		Redistribution not permitted
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/${WRKNAME}
BUILD_DIRS=		# empty
DIST_SUBDIR=		flash/${FLASH_VERS}

CRYPTO=			yes

EMUL_PLATFORMS=		linux-i386
EMUL_PLATFORMS+=	solaris-sparc
EMUL_MODULES.linux=	compat gtk2 x11
EMUL_REQD=		suse>=9.0

.include "../../mk/bsd.prefs.mk"

.if ${EMUL_PLATFORM} == "solaris-sparc"
FLASH_VERS=		7.0r67
PKGREVISION=		2
DISTUNAME=		solaris
DISTNAME=		install_flash_player_7_${DISTUNAME}_sparc
WRKNAME=		install_flash_player_7_${DISTUNAME}
.else  # if ${EMUL_PLATFORM} == "linux-i386"
# Defaults so lintpkgsrc is happy
FLASH_VERS=		9.0r151
DISTUNAME=		linux
DISTNAME=		install_flash_player_9
WRKNAME=		install_flash_player_9_${DISTUNAME}
.endif

PKGNAME=		ns-flash-${FLASH_VERS:S/r/./}

NS_PLUGINS_DIR=		${PREFIX}/lib/netscape/plugins

.include "options.mk"

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${NS_PLUGINS_DIR}
	${INSTALL_DATA} ${WRKSRC}/libflashplayer.so ${DESTDIR}${NS_PLUGINS_DIR}

.include "../../mk/bsd.pkg.mk"
