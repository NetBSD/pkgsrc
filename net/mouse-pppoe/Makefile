# $NetBSD: Makefile,v 1.1.1.1 2000/02/04 03:58:37 hubertf Exp $

DISTNAME=		mouse_pppoe
PKGNAME=		${DISTNAME}-20000202
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.styx.org/pub/mouse_pppoe/

MAINTAINER=		mouse@netbsd.org

DIST_SUBDIR=		${PKGNAME}-20000202
WRKSRC=			${WRKDIR}/${DISTNAME}

do-build:
	(cd ${WRKSRC} ; ${CC} -O2 -o pppoe pppoe.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pppoe ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
