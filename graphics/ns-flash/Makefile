# $NetBSD: Makefile,v 1.2 1999/10/04 17:31:24 jlam Exp $
#

PKGNAME=		ns-flash-4.0r12
FLASH_VERS=		${PKGNAME:S/ns-flash-//}

ONLY_FOR_PLATFORM=      *-*-i386 *-*-sparc

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "i386")
.if !exists(/emul/linux/lib/ld-linux.so.2)
IGNORE=		requires Linux glibc2 libraries - see compat_linux(8)
.endif
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

NO_CDROM=               "Redistribution not permitted"
RESTRICTED=             "Export-controlled"
MIRROR_DISTFILE=        no

NO_CONFIGURE=		yes
NO_BUILD=		yes

WRKSRC=			${WRKDIR}/${WRKNAME}
NS_PLUGINS_DIR=		${PREFIX}/lib/netscape/plugins

do-install:
	${INSTALL_DATA_DIR} ${NS_PLUGINS_DIR}
	${INSTALL_DATA} ${WRKSRC}/ShockwaveFlash.class ${NS_PLUGINS_DIR}
	${INSTALL_DATA} ${WRKSRC}/libflashplayer.so ${NS_PLUGINS_DIR}

.include "../../mk/bsd.pkg.mk"
