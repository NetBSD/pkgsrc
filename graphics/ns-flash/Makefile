# $NetBSD: Makefile,v 1.16 2002/07/02 12:47:47 wiz Exp $

DISTNAME=		flash_${DISTUNAME}
CATEGORIES=		graphics www
MASTER_SITES=		http://download.macromedia.com/pub/shockwave/flash/${SUB}/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.flash.com/
COMMENT=		MacroMedia Flash Player Netscape plugin

ONLY_FOR_PLATFORM=      *-*-i386 SunOS-*-sparc

DIST_SUBDIR=		flash/${FLASH_VERS}

.include "../../mk/bsd.prefs.mk"

SUB=			english/${DISTUNAME}/${FLASH_VERS}

.if (${MACHINE_ARCH} == "i386")
FLASH_VERS=		5.0r47
DEPENDS+=		suse_compat>=6.3:../../emulators/${SUSE_DIR_PREFIX}_compat
DEPENDS+=		suse_x11>=6.3:../../emulators/${SUSE_DIR_PREFIX}_x11
DISTUNAME=		linux
WRKNAME=		flash_linux
.elif ${MACHINE_ARCH} == "sparc" && ${OPSYS} == "SunOS"
FLASH_VERS=		5.0r52
DISTUNAME=		solaris
WRKNAME=		flash_solaris
.else
# Defaults so lintpkgsrc is happy
FLASH_VERS=		5.0
.endif
PKGNAME=		ns-flash-${FLASH_VERS:S/r/./}

# Must update communicator/navigator to at least 4.76nb1
CONFLICTS+=		communicator<=4.76nb1
CONFLICTS+=		navigator<=4.76nb1

RESTRICTED=             "Redistribution not permitted"
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

NO_CONFIGURE=		yes
NO_BUILD=		yes
CHECK_SHLIBS=		no
CRYPTO=			yes

WRKSRC=			${WRKDIR}/${WRKNAME}
NS_PLUGINS_DIR=		${PREFIX}/lib/netscape/plugins

do-install:
	${INSTALL_DATA_DIR} ${NS_PLUGINS_DIR}
	${INSTALL_DATA} ${WRKSRC}/ShockwaveFlash.class ${NS_PLUGINS_DIR}
	${INSTALL_DATA} ${WRKSRC}/libflashplayer.so ${NS_PLUGINS_DIR}

.include "../../emulators/suse_linux/Makefile.application"
