# $NetBSD: Makefile,v 1.1.1.1 1999/09/04 16:43:13 jlam Exp $
#

DISTNAME=		flash_linux
PKGNAME=		ns-flash-4.0.12
WRKSRC=			${WRKDIR}/Linux
CATEGORIES=		graphics www
MASTER_SITES=		http://download.macromedia.com/pub/shockwave/flash/english/linux/4.0r12/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.flash.com/

NO_CDROM=               "Redistribution not permitted"
RESTRICTED=             "Export-controlled"
MIRROR_DISTFILE=        no

ONLY_FOR_PLATFORM=      NetBSD-*-i386
NO_CONFIGURE=		yes
NO_BUILD=		yes

NS_PLUGINS_DIR=		${PREFIX}/lib/netscape/plugins

.if !exists(/emul/linux/lib/ld-linux.so.1)
IGNORE=         requires Linux glibc2 libraries - see compat_linux(8)
.endif

do-install:
	${INSTALL_DATA_DIR} ${NS_PLUGINS_DIR}
	${INSTALL_DATA} ${WRKSRC}/ShockwaveFlash.class ${NS_PLUGINS_DIR}
	${INSTALL_DATA} ${WRKSRC}/libflashplayer.so ${NS_PLUGINS_DIR}

.include "../../mk/bsd.pkg.mk"
