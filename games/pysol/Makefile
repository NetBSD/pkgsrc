# $NetBSD: Makefile,v 1.28 2008/04/25 20:39:09 joerg Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=	yes
PLIST_SRC=	${WRKDIR}/PLIST.src

PYTHON_VERSIONS_ACCEPTED=	21 15

CARDSETS=	pysol-cardsets-4.40

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

do-install:
	${SED} -e "s|@pkgdatadir@|${PREFIX}/share/pysol|" \
		-e "s|python|${PYTHONBIN}|" \
		< ${WRKSRC}/pysol > ${DESTDIR}${PREFIX}/bin/pysol
	${CHMOD} +x ${DESTDIR}${PREFIX}/bin/pysol
	${INSTALL_DATA} ${WRKSRC}/pysol.6 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6
	@${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/pysol
	(cd ${WRKSRC}/data; tar cf - *) | \
		(cd ${DESTDIR}${PREFIX}/share/pysol; tar xf -)
	(cd ${WRKDIR}/${CARDSETS}/data; tar cf - *) | \
		(cd ${DESTDIR}${PREFIX}/share/pysol; tar xf -)

post-install:
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	@(cd ${DESTDIR}${PREFIX}; \
	  ${FIND} share/pysol \( -type f -or -type l \) -print | \
	    ${SORT} >> ${PLIST_SRC}; \
	  for DIR in `${FIND} share/pysol -type d -print | ${SORT} -r`; do \
	  ${ECHO} "@dirrm $$DIR" >> ${PLIST_SRC}; \
	  done)

.include "../../lang/python/application.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
