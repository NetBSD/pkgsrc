# $NetBSD: Makefile,v 1.13 2002/03/17 03:37:57 jmc Exp $
#

FLASH_VERS=		${PKGNAME:S/ns-flash-//}

ONLY_FOR_PLATFORM=      *-*-i386 SunOS-*-sparc

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "i386")
PKGNAME=		ns-flash-5.0r47
DEPENDS+=		suse_compat>=6.3:../../emulators/suse_compat
DEPENDS+=		suse_x11>=6.3:../../emulators/suse_x11
DISTUNAME=		linux
WRKNAME=		flash_linux
.elif ${MACHINE_ARCH} == "sparc" && ${OPSYS} == "SunOS"
PKGNAME=		ns-flash-5.0r52
DISTUNAME=		solaris
WRKNAME=		flash_solaris
.else
# Defaults so lintpkgsrc is happy
PKGNAME=		ns-flash-5.0
.endif

DISTNAME=		flash_${DISTUNAME}
DIST_SUBDIR=		flash/${FLASH_VERS}
CATEGORIES=		graphics www
SUB=			english/${DISTUNAME}/${FLASH_VERS}
MASTER_SITES=		http://download.macromedia.com/pub/shockwave/flash/${SUB}/

# Must update communicator/navigator to at least 4.76nb1
CONFLICTS+=		communicator<=4.76nb1
CONFLICTS+=		navigator<=4.76nb1

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.flash.com/
COMMENT=		MacroMedia Flash Player Netscape plugin

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

.include "../../mk/bsd.pkg.mk"
