# $NetBSD: Makefile,v 1.6 2008/03/04 06:59:04 jlam Exp $
#

DISTNAME=		genecys-data-0.2
PKGREVISION=		2
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=genecys/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.genecys.org/
COMMENT=		Game datafiles for Genecys

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}
NO_BUILD=		YES
NO_CONFIGURE=		YES
USE_TOOLS+=		gtar

do-extract:

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/genecys
	cd ${DESTDIR}${PREFIX}/share/genecys && \
		${GZCAT} ${DISTDIR}/${DISTFILES} | ${GTAR} xmf -

.include "../../mk/bsd.pkg.mk"
