# $NetBSD: Makefile,v 1.68 2013/01/08 15:09:59 darcy Exp $

DISTNAME=		PyGreSQL-4.1.1
PKGNAME=		${PYPKGPREFIX}-postgresql-4.1.1
CATEGORIES=		databases python
MASTER_SITES=		http://pygresql.org/files/
EXTRACT_SUFX=		.tgz

OWNER=			darcy@NetBSD.org
HOMEPAGE=		http://www.PyGreSQL.org/
COMMENT=		Python interface to PostgreSQL

MAKE_ENV+=		MANDIR=${PREFIX}/${PKGMANDIR}
MAKE_ENV+=		BINDIR=${PREFIX}/bin
USE_TOOLS+=		gmake
LICENSE=        postgresql-license

MAKE_FILE=		GNUmakefile
MAKE_ENV+=		INSTALLED_LIBPQ=1

PY_PATCHPLIST=		yes
PLIST_SUBST+=		PYPKGPREFIX=${PYPKGPREFIX:Q}
REPLACE_PYTHON=		pg.py pgdb.py

PYDISTUTILSPKG=		yes
DOCDIR=			${PREFIX}/share/doc/${PYPKGPREFIX}-postgresql

INSTALLATION_DIRS=	${DOCDIR}/tutorial ${DOCDIR}/docs

post-install:
	set -e;								\
	cd ${WRKSRC}/tutorial;						\
	for f in *.py; do						\
		${INSTALL_DATA} "$$f" ${DESTDIR}${DOCDIR}/tutorial;	\
	done
	set -e;								\
	cd ${WRKSRC}/docs;						\
	for f in *; do							\
		${INSTALL_DATA} "$$f" ${DESTDIR}${DOCDIR}/docs;		\
	done

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
