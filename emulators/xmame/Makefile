# $NetBSD: Makefile,v 1.29 1999/02/20 22:48:28 hubertf Exp $
#

DISTNAME=		xmame-0.34b8.1
CATEGORIES=		emulators games x11
MASTER_SITES=		http://xmame.retrogames.com/download/
EXTRACT_SUFX=		.tgz

MAINTAINER=		mycroft@NetBSD.ORG
HOMEPAGE=		http://xmame.retrogames.com/

DEPENDS=		unzip-5.40:../../archivers/unzip
DEPENDS+=		xpm-3.4k:../../graphics/xpm

NOT_FOR_ARCHS=		alpha	#gcc lossage

USE_X11BASE=		yes
USE_GMAKE=		yes
MAKE_ENV+=		OPSYS=${OPSYS} ARCH=${ARCH} DESTDIR=${DESTDIR} \
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
.if exists(/usr/X11R6/include/X11/extensions/xf86dga.h)
NETBSD_DGA=		yes
.else
NETBSD_DGA=		no
.endif

post-patch:
	(cd ${WRKSRC}/doc && ${SED} 's|@ROMPATH@|${ROMPATH}|;s|@SPOOLDIR@|${SPOOLDIR}|' xmamerc.dist >xmamerc)
	(cd ${WRKSRC}/src/unix && ${MV} netbsd_i386.c netbsd.c)

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} xmame.${DISPLAY_METHOD} ${PREFIX}/bin/xmame)
	(cd ${WRKSRC}/doc && ${INSTALL_MAN} xmame.man ${PREFIX}/man/man6/xmame.6)
	${MKDIR} ${ROMPATH}
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} xmamerc ${ROMPATH}/xmamerc)
	@${ECHO} Remember to set ROMPATH to ${ROMPATH}.

.include "../../mk/bsd.pkg.mk"
