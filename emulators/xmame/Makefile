# $NetBSD: Makefile,v 1.39 2000/11/05 00:43:30 mycroft Exp $
#

DISTNAME=		xmame-0.37b6.1
CATEGORIES=		emulators games x11
MASTER_SITES=		http://x.mame.net/download/
EXTRACT_SUFX=		.tgz

MAINTAINER=		soren@netbsd.org
HOMEPAGE=		http://x.mame.net/

DEPENDS=		unzip>=5.40:../../archivers/unzip

USE_X11BASE=		YES
USE_XPM=		YES
USE_GMAKE=		YES
MAKE_ENV+=		OPSYS=${OPSYS} ARCH=${ARCH} \
			MAME_CPU=${MAME_CPU} \
			INSTALL_MAN="${INSTALL_MAN}" \
			INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
			NETBSD_JOYSTICK="${NETBSD_JOYSTICK}" \
			NETBSD_DGA="${NETBSD_DGA}" \
			DISPLAY_METHOD="${DISPLAY_METHOD}"
MAKEFILE=		makefile.unix
DISPLAY_METHOD= 	x11

ROMPATH=		${PREFIX}/share/xmame
SPOOLDIR=		/var/games/xmame
.if exists(/usr/include/machine/joystick.h)
NETBSD_JOYSTICK=	yes
.else
NETBSD_JOYSTICK=	no
.endif
.if exists(${X11BASE}/include/X11/extensions/xf86dga.h)
NETBSD_DGA=		yes
.else
NETBSD_DGA=		no
.endif

.if ${MACHINE_ARCH} == "m68k"
MAME_CPU=		m68k
.elif ${MACHINE_ARCH} == "alpha"
MAME_CPU=		alpha
.elif ${MACHINE_ARCH} == "i386"
MAME_CPU=		i386
.elif ${MACHINE_ARCH} == "mipsel"
MAME_CPU=		risc_lsb
.else
MAME_CPU=		risc
.endif

post-patch:
	(cd ${WRKSRC}/doc && ${SED} 's|@ROMPATH@|${ROMPATH}|;s|@SPOOLDIR@|${SPOOLDIR}|' \
		xmamerc.dist >xmamerc)

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} xmame.${DISPLAY_METHOD} \
		${PREFIX}/bin/xmame)
	(cd ${WRKSRC}/doc && ${INSTALL_MAN} xmame.6 \
		${PREFIX}/man/man6/xmame.6)
	${MKDIR} ${ROMPATH}
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} xmamerc ${ROMPATH}/xmamerc)
	@${ECHO} Remember to set ROMPATH to ${ROMPATH}.

.include "../../mk/bsd.pkg.mk"
