# $NetBSD: Makefile,v 1.116 2024/05/06 08:00:28 jperkin Exp $

.include "Makefile.common"

COMMENT=	CRT screen handling and optimization package

PLIST_SRC=	${PKGDIR}/PLIST ${WRKDIR}/PLIST.terminfo

post-configure:
	cd ${WRKSRC}/man;					\
	for f in *.1m; do					\
		mv -f $${f} `${BASENAME} $${f} .1m`.1; 	\
	done;							\
	for f in *.3x; do					\
		mv -f $${f} `${BASENAME} $${f} .3x`.3; 	\
	done

post-install:
.if ${OPSYS} == "Darwin"
	# Clashes with "a" versions on case-insensitive file systems
	${RM} -f ${DESTDIR}${PREFIX}/${TERMINFODIR}/32/2621A
	${RM} -f ${DESTDIR}${PREFIX}/${TERMINFODIR}/68/hp2621A
	${RM} -f ${DESTDIR}${PREFIX}/${TERMINFODIR}/68/hp70092A
.endif
	${FIND} ${DESTDIR}${PREFIX}/${TERMINFODIR} -type f -print | ${SORT} | \
	${SED} -e "s,^${DESTDIR}${PREFIX}/,," >${WRKDIR}/PLIST.terminfo
	${RM} -f ${DESTDIR}${PREFIX}/lib/terminfo

.include "../../mk/bsd.pkg.mk"
