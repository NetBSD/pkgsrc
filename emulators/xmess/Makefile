# $NetBSD: Makefile,v 1.10 1999/02/20 22:48:29 hubertf Exp $
#

DISTNAME=		unix02b4
PKGNAME=		xmess-0.2b4.1
CATEGORIES=		emulators games x11
MASTER_SITES=		http://internetter.com/titan/mess/
EXTRACT_SUFX=		.tgz

MAINTAINER=		mycroft@NetBSD.ORG
HOMEPAGE=		http://internetter.com/titan/mess/

DEPENDS=		unzip-5.40:../../archivers/unzip
DEPENDS+=		xpm-3.4k:../../graphics/xpm

NOT_FOR_ARCHS=		alpha	#gcc lossage

USE_X11BASE=		yes
USE_GMAKE=		yes
MAKE_ENV+=		OPSYS=${OPSYS} ARCH=${ARCH} DESTDIR=${DESTDIR} \
			INSTALL_MAN="${INSTALL_MAN}" \
			INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
			NETBSD_JOYSTICK="${NETBSD_JOYSTICK}" \
			DISPLAY_METHOD="${DISPLAY_METHOD}"
MAKEFILE=		makefile.unix
DISPLAY_METHOD=		x11
ALL_TARGET=		xmess.${DISPLAY_METHOD}

WRKSRC=			${WRKDIR}/xmess-0.2b4.1

MESSDIR=		${PREFIX}/share/xmess
.if exists(/usr/include/machine/joystick.h)
NETBSD_JOYSTICK=	yes
.else
NETBSD_JOYSTICK=	no
.endif

post-patch:
	(cd ${WRKSRC}/doc && ${SED} 's|@MESSDIR@|${MESSDIR}|' xmessrc.dist >xmessrc)
	(cd ${WRKSRC}/src/unix && ${MV} netbsd_i386.c netbsd.c)

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${ALL_TARGET} ${PREFIX}/bin/xmess)
	${MKDIR} ${MESSDIR}
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} xmessrc ${MESSDIR}/xmessrc)
	@${ECHO} Remember to set MESSDIR to ${MESSDIR}.

.include "../../mk/bsd.pkg.mk"
