# $NetBSD: Makefile,v 1.12 2001/11/29 01:12:28 hubertf Exp $
#

DISTNAME=	ZMySQLDA-1.1.3-nonbin
PKGNAME=	zope-mysql-1.1.3
PKGREVISION=	2
CATEGORIES=	databases www
MASTER_SITES=   http://www.zope.org/Members/MikeP/ZMySQLDA/

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.zope.org/Members/MikeP/ZMySQLDA
COMMENT=	Zope Database Adaptor for MySQL

DEPENDS+=	zope-2.*:../../www/zope
DEPENDS+=	py-mysqldb-0.1.3:../../databases/py-mysqldb

WRKSRC=		${WRKDIR}/lib

PLIST_SRC=	${WRKDIR}/.PLIST_SRC

ZOPEDIR=	${PREFIX}/lib/zope
DAPATH=		lib/python/Products/ZMySQLDA

do-configure:
	(cd ${WRKDIR}/${DAPATH}; ${RM} -rf Makefile* *.pyc *.orig src Setup)

do-build:
	${PREFIX}/bin/python ${PREFIX}/lib/python2.0/compileall.py \
		${WRKDIR}/${DAPATH}
	${PREFIX}/bin/python -O ${PREFIX}/lib/python2.0/compileall.py \
		${WRKDIR}/${DAPATH}

do-install:
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	(cd ${WRKDIR}; ${PAX} -r -w lib ${ZOPEDIR})
	${CHMOD} -R a+rX ${ZOPEDIR}/${DAPATH}
	(cd ${PREFIX}; ${FIND} lib/zope/${DAPATH} -type f -print >>${PLIST_SRC})
	${ECHO} "@dirrm lib/zope/${DAPATH}" >> ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
