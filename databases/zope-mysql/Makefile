# $NetBSD: Makefile,v 1.9 2000/03/11 19:59:56 tsarna Exp $
#

DISTNAME=	ZMySQLDA-1.1.3-nonbin
PKGNAME=	zope-mysql-1.1.3nb2
CATEGORIES=	databases www
MASTER_SITES=   http://www.zope.org/Members/MikeP/ZMySQLDA/

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.zope.org/Members/MikeP/ZMySQLDA

DEPENDS+=	zope-2.*:../../www/zope
DEPENDS+=	py-mysqldb-0.1.3:../../databases/py-mysqldb

WRKSRC=		${WRKDIR}/lib

PLIST_SRC=	${WRKDIR}/.PLIST_SRC

ZOPEDIR=	${PREFIX}/lib/zope
DAPATH=		lib/python/Products/ZMySQLDA

do-configure:
	(cd ${WRKDIR}/${DAPATH}; ${RM} -rf Makefile* *.pyc *.orig src Setup)

do-build:
	${PREFIX}/bin/python ${PREFIX}/lib/python1.5/compileall.py \
		${WRKDIR}/${DAPATH}
	${PREFIX}/bin/python -O ${PREFIX}/lib/python1.5/compileall.py \
		${WRKDIR}/${DAPATH}

do-install:
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	(cd ${WRKDIR}; ${PAX} -r -w lib ${ZOPEDIR})
	${CHMOD} -R a+rX ${ZOPEDIR}/${DAPATH}
	(cd ${PREFIX}; ${FIND} lib/zope/${DAPATH} -type f -print >>${PLIST_SRC})
	${ECHO} "@dirrm lib/zope/${DAPATH}" >> ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
