# $NetBSD: Makefile,v 1.25 2006/09/03 00:56:29 wiz Exp $
#

DISTNAME=	pysol-4.81
PKGREVISION=	3
CATEGORIES=	games python
MASTER_SITES=	http://www.pysol.org/download/pysol/
EXTRACT_SUFX=	.tar.bz2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${CARDSETS}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pysol.org/
COMMENT=	Solitaire game, written in Python

NO_BUILD=	yes
PLIST_SRC=	${WRKDIR}/PLIST.src

PYTHON_VERSIONS_ACCEPTED=	22 21 20 15

CARDSETS=	pysol-cardsets-4.40

INSTALLATION_DIRS=	bin man/man6

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
