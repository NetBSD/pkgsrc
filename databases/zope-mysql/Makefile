# $NetBSD: Makefile,v 1.1.1.1 1998/12/19 18:39:25 tsarna Exp $
#

DISTNAME=	ZmySQLDA-1.0.5-nonbin
PKGNAME=	zope-mysql-1.0.5
CATEGORIES=	www
MASTER_SITES=   http://www.zope.org/Download/ZmySQLDA/

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.zope.org/

DEPENDS+=	zope-1.9.0b3:../../www/zope
DEPENDS+=	py-mysql-1.4:../../databases/py-mysql

WRKSRC=		${WRKDIR}/lib

PLIST_SRC=	${WRKDIR}/.PLIST_SRC

ZOPEDIR=	${PREFIX}/zope
DAPATH=		lib/python/Products/ZmySQLDA

do-configure:
	(cd ${WRKDIR}/${DAPATH}; ${RM} -f Makefile* *.pyc *.orig Setup)

do-build:
	(cd ${WRKDIR}/${DAPATH} ; \
	${PREFIX}/bin/python ${PREFIX}/lib/python1.5/compileall.py . ; \
	${PREFIX}/bin/python -O ${PREFIX}/lib/python1.5/compileall.py . ; )
	
do-install:
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	(cd ${WRKDIR}; pax -r -w lib ${ZOPEDIR})
	chmod -R a+rX ${ZOPEDIR}/${DAPATH}
	(cd ${PREFIX}; find zope/${DAPATH} -type f -print >>${PLIST_SRC})
	${ECHO} "@dirrm zope/${DAPATH}" >> ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
