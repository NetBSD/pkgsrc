# $NetBSD: Makefile,v 1.2 2004/04/24 22:44:50 wiz Exp $

DISTNAME=		flash_${DISTUNAME}
CATEGORIES=		multimedia www
MASTER_SITES=		http://download.macromedia.com/pub/shockwave/flash/${SUB}/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.flash.com/
COMMENT=		MacroMedia Flash Player Netscape plugin

ONLY_FOR_PLATFORM=      *-*-i386 SunOS-*-sparc
NOT_FOR_PLATFORM=	SunOS-*-i386

WRKSRC=			${WRKDIR}/${WRKNAME}
DIST_SUBDIR=		flash/${FLASH_VERS}

.include "../../mk/bsd.prefs.mk"

SUB=			english/${DISTUNAME}/${FLASH_VERS}

.if (${MACHINE_ARCH} == "i386")
FLASH_VERS=		5.0r51
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

NO_BUILDLINK=		yes
NO_CONFIGURE=		yes
NO_BUILD=		yes
CHECK_SHLIBS=		no
CRYPTO=			yes

NS_PLUGINS_DIR=		${PREFIX}/lib/netscape/plugins

do-install:
	${INSTALL_DATA_DIR} ${NS_PLUGINS_DIR}
	${INSTALL_DATA} ${WRKSRC}/ShockwaveFlash.class ${NS_PLUGINS_DIR}
	${INSTALL_DATA} ${WRKSRC}/libflashplayer.so ${NS_PLUGINS_DIR}

.if ${OPSYS} != "SunOS"
.include "../../emulators/suse_linux/Makefile.application"
.endif
.include "../../mk/bsd.pkg.mk"
