# $NetBSD: Makefile,v 1.4 2005/07/15 18:27:50 jlam Exp $
#

DISTNAME=		genecys-data-0.2
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=genecys/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.genecys.org/
COMMENT=		Game datafiles for Genecys

WRKSRC=			${WRKDIR}
NO_BUILD=		YES
NO_CONFIGURE=		YES
USE_TOOLS+=		gtar

do-extract:
do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/genecys
	cd ${PREFIX}/share/genecys && \
		${GZCAT} ${DISTDIR}/${DISTFILES} | ${GTAR} xmf -
	${CHOWN} -R ${ROOT_USER}:games ${PREFIX}/share/genecys

.include "../../mk/bsd.pkg.mk"
