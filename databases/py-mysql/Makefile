# $NetBSD: Makefile,v 1.10 1998/12/18 00:42:39 tsarna Exp $

DISTNAME=	MySQLmodule-1.4
PKGNAME=	py-mysql-1.4
CATEGORIES=	databases
MASTER_SITES=	http://snail.earthlight.co.nz/mysql/
DISTFILES=	MySQLmodule-1.4${EXTRACT_SUFX} \
		Mysqldb.py mysqlshelve.py

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://snail.earthlight.co.nz/projects.html

DEPENDS+=	python-1.5.1:../../lang/python \
		mysql>=3.21:../../databases/mysql

CONFLICTS=	py-mysql-1.1

EXTRACT_ONLY=	MySQLmodule-1.4${EXTRACT_SUFX}
ALL_TARGET=	default

do-configure:
	${SED} -e 's,@PREFIX@,${PREFIX},' ${FILESDIR}/Setup.in \
		>${WRKSRC}/Setup.in
	${CP} ${PREFIX}/lib/python1.5/config/Makefile.pre.in ${WRKSRC}
	(cd ${WRKSRC}; make -f Makefile.pre.in boot)
	${CP} ${DISTDIR}/Mysqldb.py ${DISTDIR}/mysqlshelve.py ${WRKSRC}

post-build:
	(cd ${WRKSRC}; python ${PREFIX}/lib/python1.5/compileall.py .)
	(cd ${WRKSRC}; python -O ${PREFIX}/lib/python1.5/compileall.py .)

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/*.py ${WRKSRC}/*.py[co] \
		${PREFIX}/lib/python1.5/site-packages

.include "../../mk/bsd.pkg.mk"
