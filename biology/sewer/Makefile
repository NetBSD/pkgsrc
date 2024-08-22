# $NetBSD: Makefile,v 1.13 2024/08/22 17:01:17 gdt Exp $

DISTNAME=		sewer
PKGNAME=		sewer-2.6
PKGREVISION=		2
CATEGORIES=		biology
#MASTER_SITES=		ftp://iubio.bio.indiana.edu/molbio/analyze/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBDS.org
#HOMEPAGE=		http://iubio.bio.indiana.edu/webapps/SeWeR/
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
