# $NetBSD: Makefile,v 1.4 2001/02/16 14:17:38 wiz Exp $

DISTNAME=	MySQLdb-0.1.3
PKGNAME=	py-mysqldb-0.1.3
CATEGORIES=	databases
MASTER_SITES=	ftp://starship.python.net/pub/crew/adustman/

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://starship.python.net/crew/adustman/MySQLdb.html
COMMENT=	MySQL interface for Python

DEPENDS+=	python>=2.0:../../lang/python
DEPENDS+=	mysql-client-3.22.32:../../databases/mysql-client

ALL_TARGET=	default

do-configure:
	${SED} -e 's,@PREFIX@,${PREFIX},g' ${FILESDIR}/Setup.in \
		>${WRKSRC}/Setup.in
	${CP} ${PREFIX}/lib/python2.0/config/Makefile.pre.in ${WRKSRC}
	(cd ${WRKSRC}; ${MAKE} -f Makefile.pre.in boot)

post-build:
	(cd ${WRKSRC}; ${PREFIX}/bin/python -c "import MySQLdb")
	(cd ${WRKSRC}; ${PREFIX}/bin/python -O -c "import MySQLdb")

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/MySQLdb.py ${WRKSRC}/MySQLdb.py[co] \
		${PREFIX}/lib/python2.0/site-packages

.include "../../mk/bsd.pkg.mk"
