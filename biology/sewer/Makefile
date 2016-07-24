# $NetBSD: Makefile,v 1.11 2016/07/24 21:21:13 rillig Exp $

DISTNAME=		sewer
PKGNAME=		sewer-2.6
PKGREVISION=		2
CATEGORIES=		biology
MASTER_SITES=		ftp://iubio.bio.indiana.edu/molbio/analyze/
EXTRACT_SUFX=		.zip

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		http://iubio.bio.indiana.edu/webapps/SeWeR/
COMMENT=		SEquence Analysis using WEb Resources

USE_TOOLS+=		pax
NO_CONFIGURE=		YES
NO_BUILD=		YES
WRKSRC=			${WRKDIR}
AUTO_MKDIRS=		yes

pre-install:
	cd ${WRKSRC} && ${RM} -fr readme.txt* CVS */CVS

do-install:
	cd ${WRKSRC} && pax -rw [a-z]* ${DESTDIR}${PREFIX}/share/doc/sewer/
	${LN} -s sewer.htm ${DESTDIR}${PREFIX}/share/doc/sewer/index.html

.include "../../mk/bsd.pkg.mk"
