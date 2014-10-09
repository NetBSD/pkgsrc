# $NetBSD: Makefile,v 1.10 2014/10/09 14:06:01 wiz Exp $

DISTNAME=		sewer
PKGNAME=		sewer-2.6
PKGREVISION=		1
CATEGORIES=		biology
MASTER_SITES=		ftp://iubio.bio.indiana.edu/molbio/analyze/
EXTRACT_SUFX=		.zip

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		http://iubio.bio.indiana.edu/webapps/SeWeR/
COMMENT=		SEquence Analysis using WEb Resources

USE_TOOLS+=	pax

NO_CONFIGURE=		YES
NO_BUILD=		YES

WRKSRC=			${WRKDIR}

pre-install:
.for goner in readme.txt* CVS images/CVS styles/CVS scripts/CVS
	${RM} -fr ${WRKDIR}/${goner}
.endfor

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/html/sewer
	cd ${WRKDIR} && pax -rw [a-z]* \
		${DESTDIR}${PREFIX}/share/doc/html/sewer/
	cd ${DESTDIR}${PREFIX}/share/doc/html/sewer && \
		${LN} -s sewer.htm index.html

.include "../../mk/bsd.pkg.mk"
