# $NetBSD: Makefile,v 1.12 2002/09/21 23:46:50 jlam Exp $
# FreeBSD Id: ports/games/pysol/Makefile,v 1.20 1999/12/08 11:01:01 tg Exp

DISTNAME=       pysol-4.72
CATEGORIES=	games
MASTER_SITES=	http://wildsau.idv.uni-linz.ac.at/mfx/download/pysol/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${CARDSETS}${EXTRACT_SUFX}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://wildsau.idv.uni-linz.ac.at/mfx/pysol.html
COMMENT=	Solitaire game, written in Python

NO_BUILD=	yes
PLIST_SRC=	${WRKDIR}/PLIST.src

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
	  ${FIND} share/pysol \( -type f -or -type l \) | \
	    sort >> ${PLIST_SRC}; \
	  for DIR in `${FIND} share/pysol -type d | sort -r`; do \
	  ${ECHO} "@dirrm $$DIR" >> ${PLIST_SRC}; \
	  done)

.include "../../lang/python/application.mk"
.include "../../x11/py-Tk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
