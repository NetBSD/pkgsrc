# $NetBSD: Makefile,v 1.6 1998/04/24 09:20:34 agc Exp $
#

DISTNAME=		xmame-0.30.1_src
PKGNAME=		xmame-0.30.1
CATEGORIES=		emulators games x11
MASTER_SITES=		ftp://drake.dit.upm.es/pub/emulators/mame/
EXTRACT_SUFX=		.tgz

MAINTAINER=		mycroft@NetBSD.ORG

RUN_DEPENDS=		unzip:../../archivers/unzip
DEPENDS+=		xpm-3.4j:../../graphics/xpm

WRKSRC=			${WRKDIR}/xmame-0.30.1
USE_X11=		yes
USE_GMAKE=		yes
MAKE_ENV+=		OPSYS=${OPSYS} ARCH=${ARCH} DESTDIR=${DESTDIR} \
			INSTALL_MAN="${INSTALL_MAN}" \
			INSTALL_PROGRAM="${INSTALL_PROGRAM}"

MAN6=	xmame.6

post-patch:
	${CP} ${WRKSRC}/makefile.unix ${WRKSRC}/Makefile
	${SED} 's/XXX/${PREFIX:S/\//\\\//g}\/lib\/mame/' ${WRKSRC}/doc/xmamerc.dist >${WRKSRC}/doc/xmamerc
	${MV} ${WRKSRC}/src/unix/netbsd_i386.c ${WRKSRC}/src/unix/NetBSD.c

post-install:
	${MKDIR} ${PREFIX}/lib/mame
	${CP} ${WRKSRC}/doc/xmamerc ${PREFIX}/lib/mame/xmamerc
	@echo Remember to set MAMEDIR to ${PREFIX}/lib/mame.

.include "../../mk/bsd.pkg.mk"
