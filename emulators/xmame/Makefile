#
# New ports collection makefile for:	xmame
# Version required:			0.30.1
# Date Created:				30 January 1998
# Whom:					root@garbled.futureone.com
#
# $NetBSD: Makefile,v 1.1 1998/02/14 22:06:04 tron Exp $

DISTNAME=		xmame-0.30.1_src
PKGNAME=		xmame-0.30.1
CATEGORIES=		emulators games x11
MASTER_SITES=		ftp://drake.dit.upm.es/pub/emulators/mame/
EXTRACT_SUFX=		.tgz

MAINTAINER=		root@garbled.futureone.com

RUN_DEPENDS=		unzip:${PORTSDIR}/archivers/unzip

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

.include <bsd.port.mk>
