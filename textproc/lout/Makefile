# $NetBSD: Makefile,v 1.4 2000/06/16 02:13:23 itojun Exp $
#

DISTNAME=	lout-3.21
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.cs.usyd.edu.au/jeff/lout/

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://snark.niif.spb.su/~uwe/lout/lout.html

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
