# $NetBSD: Makefile,v 1.2 2000/03/11 19:49:44 tsarna Exp $

DISTNAME=	MySQLdb-0.1.3
PKGNAME=	py-mysqldb-0.1.3
CATEGORIES=	databases
MASTER_SITES=	ftp://starship.python.net/pub/crew/adustman/

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://starship.python.net/crew/adustman/MySQLdb.html

DEPENDS+=	python-1.5.2:../../lang/python
DEPENDS+=	mysql-client-3.22.32:../../databases/mysql-client

ALL_TARGET=	default

do-configure:
	${SED} -e 's,@PREFIX@,${PREFIX},g' ${FILESDIR}/Setup.in \
		>${WRKSRC}/Setup.in
	${CP} ${PREFIX}/lib/python1.5/config/Makefile.pre.in ${WRKSRC}
	(cd ${WRKSRC}; ${MAKE} -f Makefile.pre.in boot)

post-build:
	(cd ${WRKSRC}; ${PREFIX}/bin/python -c "import MySQLdb")
	(cd ${WRKSRC}; ${PREFIX}/bin/python -O -c "import MySQLdb")

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/MySQLdb.py ${WRKSRC}/MySQLdb.py[co] \
		${PREFIX}/lib/python1.5/site-packages

.include "../../mk/bsd.pkg.mk"
