# $NetBSD: Makefile,v 1.1.1.1 2001/01/20 02:18:02 jtb Exp $

DISTNAME=		PROJ.4.3.3
PKGNAME=		proj-4.3.3
CATEGORIES=		misc
MASTER_SITES=		ftp://kai.er.usgs.gov/pub/Proj.4/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} PROJ.4.3.ps.gz \
			OF90-284.ps.gz SWISS.ps.gz

MAINTAINER=		jtb@netbsd.org
HOMEPAGE=		http://kai.er.usgs.gov/intro/MAPGENdetails.html

WRKSRC=			${WRKDIR}/PROJ.4
EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=		${PKGNAME}
GNU_CONFIGURE=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES

do-build:
	(cd ${WRKSRC}/src && ${GMAKE})

do-install:
	(cd ${WRKSRC}/src && ${GMAKE} install)
	${INSTALL_DATA} ${WRKSRC}/src/projects.h ${PREFIX}/include
	${INSTALL_DATA_DIR} ${PREFIX}/share/proj
	@for i in GL27 nad27 nad83 proj_def.dat world; do \
	c="${INSTALL_DATA} ${WRKSRC}/nad/$$i ${PREFIX}/share/proj/"; \
	${ECHO} $$c; $$c; \
	done
	@for i in ${WRKSRC}/man/man1/*; do \
	c="${INSTALL_DATA} $$i ${PREFIX}/man/man1/"; \
	${ECHO} $$c; $$c; \
	done
	${INSTALL_DATA} ${WRKSRC}/man/man3/pj_init.3 ${PREFIX}/man/man3/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/proj
	@for d in PROJ.4.3.ps.gz OF90-284.ps.gz SWISS.ps.gz; do \
	c="${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/$$d ${PREFIX}/share/doc/proj/"; \
	${ECHO} $$c; $$c; \
	done

.include "../../mk/bsd.pkg.mk"
