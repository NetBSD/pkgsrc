# $NetBSD: Makefile,v 1.5 2012/10/08 09:21:06 asau Exp $

DISTNAME=	libflashsupport-pulse-20081219
PKGREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://www.invisible.ca/~jmcneill/netbsd/libflashsupport/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pulseaudio.org/wiki/FlashPlayer9Solution
COMMENT=	PulseAudio support for Adobe Flash

CONFLICTS=	libflashsupport-[0-9]*

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	base openssl x11 gtk2
EMUL_REQD=		suse>=11.0

WRKSRC=			${WRKDIR}
BUILD_DIRS=		# empty

INSTALLATION_DIRS=	${EMULSUBDIR}/usr/lib

do-install:
	${INSTALL_LIB} ${WRKDIR}/usr/lib/libflashsupport.so \
		${DESTDIR}${PREFIX}/${EMULSUBDIR}/usr/lib

.include "../../mk/bsd.pkg.mk"
