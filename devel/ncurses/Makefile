# $NetBSD: Makefile,v 1.108 2020/03/28 07:55:54 wiz Exp $

.include "Makefile.common"
PKGREVISION=	1

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
	${FIND} ${DESTDIR}${PREFIX}/${TERMINFODIR} -type f -print | ${SORT} | \
	${SED} -e "s,^${DESTDIR}${PREFIX}/,," >${WRKDIR}/PLIST.terminfo
	${RM} -f ${DESTDIR}${PREFIX}/lib/terminfo

.include "../../mk/bsd.pkg.mk"
