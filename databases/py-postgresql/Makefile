# $NetBSD: Makefile,v 1.10 2000/11/16 05:25:51 darcy Exp $

DISTNAME=	PyGreSQL-3.1
PKGNAME=	py-postgresql-3.1
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.druid.net/pub/distrib/
EXTRACT_SUFX=	.tgz

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	http://www.druid.net/pygresql/

DEPENDS+=	python-2.*:../../lang/python
DEPENDS+=	postgresql-7.*:../../databases/postgresql
DEPENDS+=	py-mxDateTime-*:../../misc/py-mxDateTime

ALL_TARGET=	default

PYTHON=		${LOCALBASE}/bin/python
PYTHON_LIBDIR=	${LOCALBASE}/lib/python2.0
PLIST_SUBST+=	PYTHON_LIBDIR=lib/python2.0

.include "../../mk/bsd.prefs.mk"

PGUSER?=	pgsql

do-configure:
	${SED}	-e "s,@LOCALBASE@,${LOCALBASE},g" \
		${FILESDIR}/Setup.in > ${WRKSRC}/Setup.in
	${CP} ${PYTHON_LIBDIR}/config/Makefile.pre.in ${WRKSRC}
	cd ${WRKSRC}; ${MAKE} -f Makefile.pre.in boot

post-build:
	cd ${WRKSRC}; ${PYTHON} ${PYTHON_LIBDIR}/compileall.py .
	cd ${WRKSRC}; ${PYTHON} -O ${PYTHON_LIBDIR}/compileall.py .

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/*.py ${WRKSRC}/*.py[co] \
		${PYTHON_LIBDIR}/site-packages
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/py-postgresql/tutorial
	${INSTALL_DATA} ${WRKSRC}/README \
		${PREFIX}/share/doc/py-postgresql
	for file in ${WRKSRC}/tutorial/*.py; do \
		${INSTALL_DATA} $${file} \
			${PREFIX}/share/doc/py-postgresql/tutorial; \
	done

.include "../../mk/bsd.pkg.mk"
