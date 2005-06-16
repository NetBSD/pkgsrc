# $NetBSD: Makefile,v 1.23 2005/06/16 06:57:44 jlam Exp $
#

DISTNAME=	ZMySQLDA-1.1.3-nonbin
PKGNAME=	zope-mysql-1.1.3
PKGREVISION=	3
CATEGORIES=	databases www
MASTER_SITES=   http://www.zope.org/Members/MikeP/ZMySQLDA/

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://www.zope.org/Members/MikeP/ZMySQLDA
COMMENT=	Zope Database Adaptor for MySQL

DEPENDS+=	zope-2.*:../../www/zope
DEPENDS+=	${PYPKGPREFIX}-mysqldb-[0-9]*:../../databases/py-mysqldb

WRKSRC=		${WRKDIR}/lib

PLIST_SRC=	${WRKDIR}/.PLIST_SRC

ZOPEDIR=	${PREFIX}/lib/zope
DAPATH=		lib/python/Products/ZMySQLDA
PYTHON_VERSIONS_ACCEPTED= 20 # XXX for now

INSTALLATION_DIRS=	lib

do-configure:
	(cd ${WRKDIR}/${DAPATH}; ${RM} -rf Makefile* *.pyc *.orig src Setup)

do-build:
	${PYTHONBIN} ${PREFIX}/lib/python2.0/compileall.py \
		${WRKDIR}/${DAPATH}
	${PYTHONBIN} -O ${PREFIX}/lib/python2.0/compileall.py \
		${WRKDIR}/${DAPATH}

do-install:
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	cd ${WRKDIR} && ${PAX} -rw lib ${ZOPEDIR}
	${CHMOD} -R a+rX ${ZOPEDIR}/${DAPATH}
	(cd ${PREFIX}; ${FIND} lib/zope/${DAPATH} -type f -print >>${PLIST_SRC})
	${ECHO} "@dirrm lib/zope/${DAPATH}" >> ${PLIST_SRC}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
