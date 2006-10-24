# $NetBSD: Makefile,v 1.5 2006/10/24 14:24:40 gdt Exp $

DISTNAME=		proj-pdf-docs
PKGNAME=		proj-doc-1.0
CATEGORIES=		misc geography
MASTER_SITES=		ftp://ftp.remotesensing.org/pub/proj/

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://www.remotesensing.org/proj/
COMMENT=		PDF documentation for the PROJ cartographic projection software

NO_BUILD=		yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/proj
	${INSTALL_DATA} ${WRKDIR}/*.pdf ${PREFIX}/share/doc/proj/

.include "../../mk/bsd.pkg.mk"
