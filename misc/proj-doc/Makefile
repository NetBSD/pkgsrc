# $NetBSD: Makefile,v 1.8 2006/12/15 18:20:39 dsainty Exp $

DISTNAME=		proj-pdf-docs
PKGNAME=		proj-doc-1.1
PKGREVISION=		1
CATEGORIES=		misc geography
MASTER_SITES=		ftp://ftp.remotesensing.org/pub/proj/ \
			http://dl.maptools.org/dl/proj/

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://www.remotesensing.org/proj/
COMMENT=		PDF documentation for the PROJ cartographic projection software

NO_BUILD=		yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/proj
	${INSTALL_DATA} ${WRKDIR}/*.pdf ${PREFIX}/share/doc/proj/

.include "../../mk/bsd.pkg.mk"
