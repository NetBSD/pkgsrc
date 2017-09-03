# $NetBSD: Makefile,v 1.4 2017/09/03 08:36:54 wiz Exp $

DISTNAME=		proj-pdf-docs
PKGNAME=		proj-doc-1.1
PKGREVISION=		1
CATEGORIES=		geography
MASTER_SITES=		ftp://ftp.remotesensing.org/pub/proj/
MASTER_SITES+=		http://dl.maptools.org/dl/proj/

MAINTAINER=		gdt@NetBSD.org
#HOMEPAGE=		http://www.remotesensing.org/proj/
COMMENT=		PDF documentation for the PROJ cartographic projection software

NO_BUILD=		yes

PREV_PKGPATH=		misc/proj-doc

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/proj
	${INSTALL_DATA} ${WRKDIR}/*.pdf ${DESTDIR}${PREFIX}/share/doc/proj/

.include "../../mk/bsd.pkg.mk"
