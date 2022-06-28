# $NetBSD: Makefile,v 1.114 2022/06/28 11:31:49 wiz Exp $

PKGREVISION= 1
.include "Makefile.common"

COMMENT=	CRT screen handling and optimization package

INSTALLATION_DIRS+=	share/examples

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
	${INSTALL_DATA} ${WRKSRC}/c++/demo.cc \
		${DESTDIR}${PREFIX}/share/examples/ncurses++demo.cc
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
