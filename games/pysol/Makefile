# $NetBSD: Makefile,v 1.20 2004/10/03 00:14:46 tv Exp $
#

DISTNAME=	pysol-4.81
PKGREVISION=	1
CATEGORIES=	games python
MASTER_SITES=	http://www.oberhumer.com/opensource/pysol/download/
EXTRACT_SUFX=	.tar.bz2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${CARDSETS}${EXTRACT_SUFX}

MAINTAINER=	sakamoto@NetBSD.org
HOMEPAGE=	http://wildsau.idv.uni-linz.ac.at/mfx/pysol.html
COMMENT=	Solitaire game, written in Python

NO_BUILD=	yes
PLIST_SRC=	${WRKDIR}/PLIST.src
USE_BUILDLINK3=	yes

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
	    ${SORT} >> ${PLIST_SRC}; \
	  for DIR in `${FIND} share/pysol -type d -print | ${SORT} -r`; do \
	  ${ECHO} "@dirrm $$DIR" >> ${PLIST_SRC}; \
	  done)

.include "../../lang/python/application.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
