# $NetBSD: Makefile,v 1.8 2013/01/11 13:25:40 joerg Exp $
#

DISTNAME=		genecys-data-0.2
PKGREVISION=		2
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=genecys/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.genecys.org/
COMMENT=		Game datafiles for Genecys

WRKSRC=			${WRKDIR}
NO_BUILD=		YES
NO_CONFIGURE=		YES
USE_TOOLS+=		bsdtar

do-extract:

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/genecys
	cd ${DESTDIR}${PREFIX}/share/genecys && \
		${GZCAT} ${DISTDIR}/${DISTFILES} | ${TOOLS_PATH.bsdtar} xmf -

.include "../../mk/bsd.pkg.mk"
