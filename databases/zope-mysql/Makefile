# $NetBSD: Makefile,v 1.7 1999/12/28 04:56:10 wiz Exp $
#

DISTNAME=	ZMySQLDA-1.1.3-nonbin
PKGNAME=	zope-mysql-1.1.3
CATEGORIES=	www
MASTER_SITES=   http://www.zope.org/Download/ZMySQLDA/

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.zope.org/

DEPENDS+=	zope-2.0.1:../../www/zope
DEPENDS+=	py-mysql-1.4:../../databases/py-mysql

WRKSRC=		${WRKDIR}/lib

PLIST_SRC=	${WRKDIR}/.PLIST_SRC

ZOPEDIR=	${PREFIX}/lib/zope
DAPATH=		lib/python/Products/ZMySQLDA

do-configure:
	(cd ${WRKDIR}/${DAPATH}; ${RM} -rf Makefile* *.pyc *.orig src Setup)

do-build:

do-install:
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	(cd ${WRKDIR}; ${PAX} -r -w lib ${ZOPEDIR})
	${CHMOD} -R a+rX ${ZOPEDIR}/${DAPATH}
	${PREFIX}/bin/python ${PREFIX}/lib/python1.5/compileall.py \
		${WRKDIR}/${DAPATH}
	(cd ${PREFIX}; ${FIND} lib/zope/${DAPATH} -type f -print >>${PLIST_SRC})
	${ECHO} "@dirrm lib/zope/${DAPATH}" >> ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
