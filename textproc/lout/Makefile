# $NetBSD: Makefile,v 1.8 2003/09/15 09:51:38 agc Exp $
#

DISTNAME=	lout-3.26
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.it.usyd.edu.au/jeff/lout/

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://www.ptc.spbu.ru/~uwe/lout/lout.html
COMMENT=	Basser Lout, a TeX/troff-like formatter with PostScript/PDF output

PLIST_SRC=      ${WRKDIR}/.PLIST_SRC
INSTALL_TARGET=	allinstall

do-configure:
	${MV} ${WRKSRC}/makefile ${WRKSRC}/makefile.in
	${SED} -e "s,@PREFIX@,${PREFIX}," <${WRKSRC}/makefile.in >${WRKSRC}/Makefile

post-install:
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	(cd ${PREFIX}; ${FIND} share/doc/lout -type f -print >>${PLIST_SRC})
	(cd ${PREFIX}; ${FIND} share/lout -type f -print >>${PLIST_SRC})
	${ECHO} "@unexec ${RM} -rf %D/share/doc/lout" >>${PLIST_SRC}
	(cd ${PREFIX}; ${FIND} -d share/lout -type d -print | \
	${SED} -e "s/^/@dirrm /" >>${PLIST_SRC})

.include "../../mk/bsd.pkg.mk"
