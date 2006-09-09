# $NetBSD: Makefile,v 1.49 2006/09/09 02:41:56 obache Exp $

DISTNAME=		PyGreSQL-3.8.1
PKGNAME=		${PYPKGPREFIX}-postgresql-3.8.1
CATEGORIES=		databases python
MASTER_SITES=		ftp://ftp.druid.net/pub/distrib/
EXTRACT_SUFX=		.tgz

MAINTAINER=		darcy@NetBSD.org
HOMEPAGE=		http://www.PyGreSQL.org/
COMMENT=		Python interface to PostgreSQL

MAKE_ENV+=		MANDIR=${LOCALBASE}/man
MAKE_ENV+=		BINDIR=${LOCALBASE}/bin
USE_TOOLS+=		gmake

MAKE_FILE=		GNUmakefile
MAKE_ENV+=		INSTALLED_LIBPQ=1

PY_PATCHPLIST=		yes
PLIST_SUBST+=		PYPKGPREFIX=${PYPKGPREFIX:Q}
PYTHON_VERSIONS_ACCEPTED=	24 23 22

PYDISTUTILSPKG=		yes
PYBINMODULE=		yes
DOCDIR=			${PREFIX}/share/doc/${PYPKGPREFIX}-postgresql

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}/tutorial
	${INSTALL_DATA_DIR} ${DOCDIR}/docs
	set -e;								\
	cd ${WRKSRC}/tutorial;						\
	for f in *.py; do						\
		${INSTALL_DATA} "$$f" ${DOCDIR}/tutorial;		\
	done
	set -e;								\
	cd ${WRKSRC}/docs;						\
	for f in *; do							\
		${INSTALL_DATA} "$$f" ${DOCDIR}/docs;			\
	done

.include "../../lang/python/extension.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
