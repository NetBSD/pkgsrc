# $NetBSD: Makefile,v 1.5 2000/04/13 03:08:44 sakamoto Exp $
# FreeBSD Id: ports/games/pysol/Makefile,v 1.20 1999/12/08 11:01:01 tg Exp

DISTNAME=       pysol-4.00
CATEGORIES=	games
MASTER_SITES=	http://wildsau.idv.uni-linz.ac.at/mfx/download/pysol/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${CARDSETS}${EXTRACT_SUFX}

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://wildsau.idv.uni-linz.ac.at/mfx/pysol.html

DEPENDS+=	py-Tk-*:../../x11/py-Tk

NO_BUILD=	yes
PLIST_SRC=	${WRKDIR}/PLIST.src

CARDSETS=	pysol-cardsets-3.40

do-install:
	${SED} -e "s|@pkgdatadir@|${PREFIX}/share/pysol|" < ${WRKSRC}/pysol > ${PREFIX}/bin/pysol
	${CHMOD} +x ${PREFIX}/bin/pysol
	${INSTALL_DATA} ${WRKSRC}/pysol.6 ${PREFIX}/man/man6
	@${MKDIR} ${PREFIX}/share/pysol
	(cd ${WRKSRC}/data; tar cf - *) | \
		(cd ${PREFIX}/share/pysol; tar xf -)
	(cd ${WRKDIR}/${CARDSETS}/data; tar cf - *) | \
		(cd ${PREFIX}/share/pysol; tar xf -)

post-install:
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	@(cd ${PREFIX}; \
	  ${FIND} share/pysol \( -type f -or -type l \) | \
	    sort >> ${PLIST_SRC}; \
	  for DIR in `${FIND} share/pysol -type d | sort -r`; do \
	  ${ECHO} "@dirrm $$DIR" >> ${PLIST_SRC}; \
	  done)

.include "../../mk/bsd.pkg.mk"
