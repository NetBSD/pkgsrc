# $NetBSD: Makefile,v 1.10 2001/02/16 15:22:28 wiz Exp $
#

PKGNAME=		ns-flash-4.0r12
FLASH_VERS=		${PKGNAME:S/ns-flash-//}

ONLY_FOR_PLATFORM=      *-*-i386 SunOS-*-sparc

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "i386")
DEPENDS+=		suse_linux>=6.1:../../emulators/suse_linux
DISTUNAME=		linux
WRKNAME=		Linux
.elif ${MACHINE_ARCH} == "sparc" && ${OPSYS} == "SunOS"
DISTUNAME=		solaris
WRKNAME=		Solaris
.endif

DISTNAME=		flash_${DISTUNAME}
CATEGORIES=		graphics www
SUB=			english/${DISTUNAME}/${FLASH_VERS}
MASTER_SITES=		http://download.macromedia.com/pub/shockwave/flash/${SUB}/

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
