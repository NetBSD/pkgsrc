# $NetBSD: Makefile,v 1.16 2004/01/27 00:53:11 heinz Exp $
#

DISTNAME=	pysol-4.81
CATEGORIES=	games
MASTER_SITES=	http://www.oberhumer.com/opensource/pysol/download/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${CARDSETS}${EXTRACT_SUFX}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	sakamoto@NetBSD.org
HOMEPAGE=	http://wildsau.idv.uni-linz.ac.at/mfx/pysol.html
COMMENT=	Solitaire game, written in Python

NO_BUILD=	yes
PLIST_SRC=	${WRKDIR}/PLIST.src
USE_BUILDLINK2=	yes

CARDSETS=	pysol-cardsets-4.40

do-install:
	${SED} -e "s|@pkgdatadir@|${PREFIX}/share/pysol|" \
		-e "s|python|${PYTHONBIN}|" \
		< ${WRKSRC}/pysol > ${PREFIX}/bin/pysol
	${CHMOD} +x ${PREFIX}/bin/pysol
	${INSTALL_DATA} ${WRKSRC}/pysol.6 ${PREFIX}/man/man6
	@${INSTALL_DATA_DIR} ${PREFIX}/share/pysol
	(cd ${WRKSRC}/data; tar cf - *) | \
		(cd ${PREFIX}/share/pysol; tar xf -)
	(cd ${WRKDIR}/${CARDSETS}/data; tar cf - *) | \
		(cd ${PREFIX}/share/pysol; tar xf -)

post-install:
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	@(cd ${PREFIX}; \
	  ${FIND} share/pysol \( -type f -or -type l \) -print | \
	    sort >> ${PLIST_SRC}; \
	  for DIR in `${FIND} share/pysol -type d -print | sort -r`; do \
	  ${ECHO} "@dirrm $$DIR" >> ${PLIST_SRC}; \
	  done)

.include "../../lang/python/application.mk"
.include "../../x11/py-Tk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
