# $NetBSD: Makefile,v 1.2 2003/07/17 21:49:48 grant Exp $

DISTNAME=		proj-pdf-docs
PKGNAME=		proj-doc-1.0
CATEGORIES=		misc
MASTER_SITES=		ftp://ftp.remotesensing.org/pub/proj/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.remotesensing.org/proj/
COMMENT=		PDF documentation for the PROJ cartographic projection software

NO_BUILD=		# defined

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/proj
	${INSTALL_DATA} ${WRKDIR}/*.pdf ${PREFIX}/share/doc/proj/

.include "../../mk/bsd.pkg.mk"
