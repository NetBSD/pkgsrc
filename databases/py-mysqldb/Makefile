# $NetBSD: Makefile,v 1.6 2002/01/19 17:06:23 drochner Exp $

DISTNAME=	MySQLdb-0.1.3
PKGNAME=	${PYPKGPREFIX}-mysqldb-0.1.3
CATEGORIES=	databases
MASTER_SITES=	ftp://starship.python.net/pub/crew/adustman/

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://starship.python.net/crew/adustman/MySQLdb.html
COMMENT=	MySQL interface for Python

DEPENDS+=	mysql-client>=3.23.35:../../databases/mysql-client

ALL_TARGET=	default

# this pkg uses Makefile.pre.in
PYTHON_VERSIONS_ACCEPTED=	20 21
BUILDLINK_DEPENDS.python20=	python20>=2.0.1nb1
BUILDLINK_DEPENDS.python21=	python21>=2.1.1nb1

PY_PATCHPLIST=	yes

do-configure:
	${SED} -e 's,@PREFIX@,${PREFIX},g' ${FILESDIR}/Setup.in \
		>${WRKSRC}/Setup.in
	${CP} ${PREFIX}/${PYLIB}/config/Makefile.pre.in ${WRKSRC}
	(cd ${WRKSRC}; ${MAKE} -f Makefile.pre.in boot)

post-build:
	(cd ${WRKSRC}; ${PYTHONBIN} -c "import MySQLdb")
	(cd ${WRKSRC}; ${PYTHONBIN} -O -c "import MySQLdb")

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/MySQLdb.py ${WRKSRC}/MySQLdb.py[co] \
		${PREFIX}/${PYSITELIB}

.include "../../lang/python/extension.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
