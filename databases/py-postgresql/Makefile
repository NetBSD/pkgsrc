# $NetBSD: Makefile,v 1.3 2000/02/24 22:41:01 darcy Exp $

DISTNAME=	PyGreSQL-2.4
PKGNAME=	py-postgresql-2.4
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.druid.net/pub/distrib/
EXTRACT_SUFX=	.tgz

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	http://www.druid.net/pygresql/

DEPENDS+=	python-1.5.2:../../lang/python
DEPENDS+=	postgresql-6.5.3:../../databases/postgresql

ALL_TARGET=	default

PYTHON=		${LOCALBASE}/bin/python
PYTHON_LIBDIR=	${LOCALBASE}/lib/python1.5
PLIST_SUBST+=	PYTHON_LIBDIR=lib/python1.5

.include "../../mk/bsd.prefs.mk"

PGUSER?=	pgsql
PGPREFIX=	${LOCALBASE}/${PGUSER}	# PostgreSQL home directory

do-configure:
	if echo __ELF__ | ${CC} -E - | grep -q __ELF__; \
	then ${SED}	-e "s+@PGPREFIX@+${PGPREFIX}+g;s+@WLFLAG@++g" \
		${FILESDIR}/Setup.in > ${WRKSRC}/Setup.in; \
	else ${SED}	-e "s+@PGPREFIX@+${PGPREFIX}+g;s+@WLFLAG@+-Wl,+" \
		${FILESDIR}/Setup.in > ${WRKSRC}/Setup.in; \
	fi
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
