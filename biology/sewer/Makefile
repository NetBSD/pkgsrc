# $NetBSD: Makefile,v 1.1.1.1 2003/09/27 23:36:34 jschauma Exp $

DISTNAME=		sewer
PKGNAME=		sewer-2.6
WRKSRC=			${WRKDIR}
CATEGORIES=		biology
MASTER_SITES=		ftp://iubio.bio.indiana.edu/molbio/analyze/
EXTRACT_SUFX=		.zip

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		http://iubio.bio.indiana.edu/webapps/SeWeR/
COMMENT=		SEquence Analysis using WEb Resources

NO_CONFIGURE=		YES
NO_BUILD=		YES

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

