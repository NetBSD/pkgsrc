# $NetBSD: Makefile,v 1.2 2004/01/20 12:08:40 agc Exp $

DISTNAME=		sewer
PKGNAME=		sewer-2.6
CATEGORIES=		biology
MASTER_SITES=		ftp://iubio.bio.indiana.edu/molbio/analyze/
EXTRACT_SUFX=		.zip

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		http://iubio.bio.indiana.edu/webapps/SeWeR/
COMMENT=		SEquence Analysis using WEb Resources

NO_CONFIGURE=		YES
NO_BUILD=		YES

WRKSRC=			${WRKDIR}
USE_BUILDLINK2=		YES

pre-install:
.for goner in readme.txt* cvs styles/cvs scripts/cvs
	${RM} -fr ${WRKDIR}/${goner}
.endfor

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/sewer
	cd ${WRKDIR} && ${PAX} -rw . ${PREFIX}/share/doc/html/sewer/
	cd ${PREFIX}/share/doc/html/sewer && ${LN} -s sewer.htm index.html

.include "../../mk/bsd.pkg.mk"

