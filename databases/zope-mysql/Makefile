# $NetBSD: Makefile,v 1.14 2002/09/21 23:46:48 jlam Exp $
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

WRKSRC=		${WRKDIR}/lib

PLIST_SRC=	${WRKDIR}/.PLIST_SRC

ZOPEDIR=	${PREFIX}/lib/zope
DAPATH=		lib/python/Products/ZMySQLDA
PYTHON_VERSIONS_ACCEPTED= 20 # XXX for now

do-configure:
	(cd ${WRKDIR}/${DAPATH}; ${RM} -rf Makefile* *.pyc *.orig src Setup)

do-build:
	${PYTHONBIN} ${PREFIX}/lib/python2.0/compileall.py \
		${WRKDIR}/${DAPATH}
	${PYTHONBIN} -O ${PREFIX}/lib/python2.0/compileall.py \
		${WRKDIR}/${DAPATH}

do-install:
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	(cd ${WRKDIR}; ${PAX} -r -w lib ${ZOPEDIR})
	${CHMOD} -R a+rX ${ZOPEDIR}/${DAPATH}
	(cd ${PREFIX}; ${FIND} lib/zope/${DAPATH} -type f -print >>${PLIST_SRC})
	${ECHO} "@dirrm lib/zope/${DAPATH}" >> ${PLIST_SRC}

.include "../../lang/python/application.mk"
.include "../../databases/py-mysqldb/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
