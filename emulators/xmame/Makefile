# $NetBSD: Makefile,v 1.12 1998/08/23 19:25:40 tron Exp $
#

DISTNAME=		xmame-0.33b6.1
CATEGORIES=		emulators games x11
MASTER_SITES=		ftp://drake.dit.upm.es/pub/emulators/mame/
EXTRACT_SUFX=		.tgz

MAINTAINER=		mycroft@NetBSD.ORG
HOMEPAGE=		http://drake.dit.upm.es/~mame/

CONFLICTS=		xmame-0.30.1

RUN_DEPENDS=		unzip:../../archivers/unzip
DEPENDS+=		xpm-3.4k:../../graphics/xpm

USE_X11=		yes
USE_GMAKE=		yes
MAKE_ENV+=		OPSYS=${OPSYS} ARCH=${ARCH} DESTDIR=${DESTDIR} \
			INSTALL_MAN="${INSTALL_MAN}" \
			INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
			NETBSD_JOYSTICK="${NETBSD_JOYSTICK}"

MAMEDIR=		${PREFIX}/share/mame
.if exists(/usr/include/machine/joystick.h)
NETBSD_JOYSTICK=	yes
.else
NETBSD_JOYSTICK=	no
.endif

post-patch:
	${CP} ${WRKSRC}/makefile.unix ${WRKSRC}/Makefile
	${SED} 's|@MAMEDIR@|${MAMEDIR}|' ${WRKSRC}/doc/xmamerc.dist >${WRKSRC}/doc/xmamerc
	${MV} ${WRKSRC}/src/unix/netbsd_i386.c ${WRKSRC}/src/unix/netbsd.c

post-install:
	${MKDIR} -p ${MAMEDIR}
	${CP} ${WRKSRC}/doc/xmamerc ${MAMEDIR}/xmamerc
	@${ECHO} Remember to set MAMEDIR to ${MAMEDIR}.

.include "../../mk/bsd.pkg.mk"
