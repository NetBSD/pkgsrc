# $NetBSD: Makefile,v 1.16 1998/09/05 12:27:39 mycroft Exp $
#

DISTNAME=		xmame-0.34b2.1
CATEGORIES=		emulators games x11
MASTER_SITES=		ftp://drake.dit.upm.es/xmame/ftpsite/
EXTRACT_SUFX=		.tgz

MAINTAINER=		mycroft@NetBSD.ORG
HOMEPAGE=		http://drake.dit.upm.es/~mame/

RUN_DEPENDS=		unzip:../../archivers/unzip
DEPENDS+=		xpm-3.4k:../../graphics/xpm

CONFLICTS=		xmame-0.30.1 xmame-0.33b6.1

USE_X11=		yes
USE_GMAKE=		yes
MAKE_ENV+=		OPSYS=${OPSYS} ARCH=${ARCH} DESTDIR=${DESTDIR} \
			INSTALL_MAN="${INSTALL_MAN}" \
			INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
			NETBSD_JOYSTICK="${NETBSD_JOYSTICK}" \
			DISPLAY_METHOD="${DISPLAY_METHOD}"
MAKEFILE=		makefile.unix
DISPLAY_METHOD=		x11
ALL_TARGET=		xmame.${DISPLAY_METHOD}

MAMEDIR=		${PREFIX}/share/xmame
.if exists(/usr/include/machine/joystick.h)
NETBSD_JOYSTICK=	yes
.else
NETBSD_JOYSTICK=	no
.endif

post-patch:
	(cd ${WRKSRC}/doc && ${SED} 's|@MAMEDIR@|${MAMEDIR}|' xmamerc.dist >xmamerc)
	(cd ${WRKSRC}/src/unix && ${MV} netbsd_i386.c netbsd.c)

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${ALL_TARGET} ${PREFIX}/bin/xmame)
	(cd ${WRKSRC}/doc && ${INSTALL_MAN} xmame.man ${PREFIX}/man/man6/xmame.6)
	${MKDIR} ${MAMEDIR}
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} xmamerc ${MAMEDIR}/xmamerc)
	@${ECHO} Remember to set MAMEDIR to ${MAMEDIR}.

.include "../../mk/bsd.pkg.mk"
