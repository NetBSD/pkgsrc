# $NetBSD: Makefile,v 1.1.1.1 2005/11/16 02:04:39 minskim Exp $
#

DISTNAME=		nstx-1.1-beta6
CATEGORIES=		net
MASTER_SITES=		http://nstx.dereference.de/nstx/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://nstx.dereference.de/nstx/
COMMENT=		Nameserver Transfer Protocol

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nstxcd ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/nstxd ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/nstx
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/nstx/

.include "../../mk/bsd.pkg.mk"
