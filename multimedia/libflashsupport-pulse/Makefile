# $NetBSD: Makefile,v 1.1.1.1 2008/12/19 19:49:22 jmcneill Exp $

DISTNAME=	libflashsupport-pulse-20081219
CATEGORIES=	multimedia
MASTER_SITES=	http://www.invisible.ca/~jmcneill/netbsd/libflashsupport/

MAINTAINER=	jmcneill@NetBSD.org
HOMEPAGE=	http://www.pulseaudio.org/wiki/FlashPlayer9Solution
COMMENT=	PulseAudio support for Adobe Flash

CONFLICTS=	libflashsupport-[0-9]*

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	base openssl x11
EMUL_REQD=		suse>=10.0

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}
BUILD_DIRS=		# empty

INSTALLATION_DIRS=	${EMULSUBDIR}/usr/lib

do-install:
	${INSTALL_LIB} ${WRKDIR}/usr/lib/libgdbm.so.3.0.0 \
		${DESTDIR}${PREFIX}/${EMULSUBDIR}/usr/lib/libgdbm.so.3
	${INSTALL_LIB} ${WRKDIR}/usr/lib/libpulse.so.0.7.0 \
		${DESTDIR}${PREFIX}/${EMULSUBDIR}/usr/lib/libpulse.so.0
	${INSTALL_LIB} ${WRKDIR}/usr/lib/libflashsupport.so \
		${DESTDIR}${PREFIX}/${EMULSUBDIR}/usr/lib

.include "../../mk/bsd.pkg.mk"
