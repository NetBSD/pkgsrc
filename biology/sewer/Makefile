# $NetBSD: Makefile,v 1.3 2004/02/18 21:13:48 minskim Exp $

DISTNAME=		sewer
PKGNAME=		sewer-2.6
CATEGORIES=		biology
MASTER_SITES=		ftp://iubio.bio.indiana.edu/molbio/analyze/
EXTRACT_SUFX=		.zip

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		http://iubio.bio.indiana.edu/webapps/SeWeR/
COMMENT=		SEquence Analysis using WEb Resources

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_BUILDLINK=		YES
NO_CONFIGURE=		YES
NO_BUILD=		YES

WRKSRC=			${WRKDIR}

pre-install:
.for goner in readme.txt* cvs images/cvs styles/cvs scripts/cvs
	${RM} -fr ${WRKDIR}/${goner}
.endfor

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/sewer
	cd ${WRKDIR} && ${PAX} -rw [a-z]* ${PREFIX}/share/doc/html/sewer/
	cd ${PREFIX}/share/doc/html/sewer && ${LN} -s sewer.htm index.html

.include "../../mk/bsd.pkg.mk"
