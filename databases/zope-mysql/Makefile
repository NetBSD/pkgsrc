# $NetBSD: Makefile,v 1.3 1999/01/09 23:16:55 tsarna Exp $
#

DISTNAME=	ZMySQLDA-1.1.2-nonbin
PKGNAME=	zope-mysql-1.1.2
CATEGORIES=	www
MASTER_SITES=   http://www.zope.org/Download/ZMySQLDA/

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.zope.org/

DEPENDS+=	zope-1.9.0:../../www/zope
DEPENDS+=	py-mysql-1.4:../../databases/py-mysql

WRKSRC=		${WRKDIR}/lib

PLIST_SRC=	${WRKDIR}/.PLIST_SRC

ZOPEDIR=	${PREFIX}/zope
DAPATH=		lib/python/Products/ZMySQLDA

do-configure:
	(cd ${WRKDIR}/${DAPATH}; ${RM} -rf Makefile* *.pyc *.orig src Setup)

do-build:
	(cd ${WRKDIR}/${DAPATH} ; \
	${PREFIX}/bin/python ${PREFIX}/lib/python1.5/compileall.py . ; )
	
do-install:
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	(cd ${WRKDIR}; pax -r -w lib ${ZOPEDIR})
	chmod -R a+rX ${ZOPEDIR}/${DAPATH}
	(cd ${PREFIX}; find zope/${DAPATH} -type f -print >>${PLIST_SRC})
	${ECHO} "@dirrm zope/${DAPATH}" >> ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
