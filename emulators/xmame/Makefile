# $NetBSD: Makefile,v 1.11 1998/08/20 15:16:53 tsarna Exp $
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
			INSTALL_PROGRAM="${INSTALL_PROGRAM}"

MAMEDIR=		${PREFIX}/share/mame

post-patch:
	${CP} ${WRKSRC}/makefile.unix ${WRKSRC}/Makefile
	${SED} 's|@MAMEDIR@|${MAMEDIR}|' ${WRKSRC}/doc/xmamerc.dist >${WRKSRC}/doc/xmamerc
	${MV} ${WRKSRC}/src/unix/netbsd_i386.c ${WRKSRC}/src/unix/netbsd.c

post-install:
	${MKDIR} -p ${MAMEDIR}
	${CP} ${WRKSRC}/doc/xmamerc ${MAMEDIR}/xmamerc
	@${ECHO} Remember to set MAMEDIR to ${MAMEDIR}.

.include "../../mk/bsd.pkg.mk"
