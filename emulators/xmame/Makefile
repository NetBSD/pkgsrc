# $NetBSD: Makefile,v 1.35 2000/03/14 11:42:47 soren Exp $
#

DISTNAME=		xmame-0.36b16.1
CATEGORIES=		emulators games x11
MASTER_SITES=		http://x.mame.net/download/
EXTRACT_SUFX=		.tgz

MAINTAINER=		soren@netbsd.org
HOMEPAGE=		http://x.mame.net/

DEPENDS=		unzip-5.40:../../archivers/unzip
DEPENDS+=		xpm-3.4k:../../graphics/xpm

USE_X11BASE=		yes
USE_GMAKE=		yes
MAKE_ENV+=		OPSYS=${OPSYS} ARCH=${ARCH} \
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
	(cd ${WRKSRC}/doc && ${SED} 's|@ROMPATH@|${ROMPATH}|;s|@SPOOLDIR@|${SPOOLDIR}|' \
		xmamerc.dist >xmamerc)

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} xmame.${DISPLAY_METHOD} \
		${PREFIX}/bin/xmame)
	(cd ${WRKSRC}/doc && ${INSTALL_MAN} xmame.man \
		${PREFIX}/man/man6/xmame.6)
	${MKDIR} ${ROMPATH}
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} xmamerc ${ROMPATH}/xmamerc)
	@${ECHO} Remember to set ROMPATH to ${ROMPATH}.

.include "../../mk/bsd.pkg.mk"
