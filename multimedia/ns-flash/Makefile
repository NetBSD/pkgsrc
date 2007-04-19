# $NetBSD: Makefile,v 1.22 2007/04/19 16:11:34 xtraeme Exp $

CATEGORIES=		multimedia www
PKGREVISION=		2
MASTER_SITES=		http://fpdownload.macromedia.com/get/flashplayer/current/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.flash.com/
COMMENT=		MacroMedia Flash Player Netscape plugin

ONLY_FOR_PLATFORM=	*-*-i386 SunOS-*-sparc
NOT_FOR_PLATFORM=	SunOS-*-i386

WRKSRC=			${WRKDIR}/${WRKNAME}
DIST_SUBDIR=		flash/${FLASH_VERS}

SUSE_COMPAT32=		yes
SUSE_COMPAT32_OPT=	yes
.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64")
FLASH_VERS=		9.0r31
DEPENDS+=		suse_compat>=9.0:../../emulators/${SUSE_DIR_PREFIX}_compat
DEPENDS+=		suse_x11>=9.0:../../emulators/${SUSE_DIR_PREFIX}_x11
DEPENDS+=		suse_gtk2>=9.0:../../emulators/${SUSE_DIR_PREFIX}_gtk2
DISTUNAME=		linux
DISTNAME=		install_flash_player_9_${DISTUNAME}
WRKNAME=		install_flash_player_9_${DISTUNAME}
.elif ${MACHINE_ARCH} == "sparc" && ${OPSYS} == "SunOS"
FLASH_VERS=		7.0r67
DISTUNAME=		solaris
DISTNAME=		install_flash_player_7_${DISTUNAME}_sparc
WRKNAME=		install_flash_player_7_${DISTUNAME}
.else
# Defaults so lintpkgsrc is happy
FLASH_VERS=		5.0
DISTNAME=		flash_player
.endif
PKGNAME=		ns-flash-${FLASH_VERS:S/r/./}

# Must update communicator/navigator to at least 4.76nb1
CONFLICTS+=		communicator<=4.76nb1
CONFLICTS+=		navigator<=4.76nb1

LICENSE=		flash-license
RESTRICTED=		Redistribution not permitted
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

NO_CONFIGURE=		yes
NO_BUILD=		yes
CRYPTO=			yes

NS_PLUGINS_DIR=		${PREFIX}/lib/netscape/plugins

do-install:
	${INSTALL_DATA_DIR} ${NS_PLUGINS_DIR}
	${INSTALL_DATA} ${WRKSRC}/flashplayer.xpt ${NS_PLUGINS_DIR}
	${INSTALL_DATA} ${WRKSRC}/libflashplayer.so ${NS_PLUGINS_DIR}

.include "options.mk"
.if ${OPSYS} != "SunOS"
.  include "../../emulators/suse_linux/Makefile.application"
.endif
.include "../../mk/bsd.pkg.mk"
