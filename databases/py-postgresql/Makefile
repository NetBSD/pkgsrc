# $NetBSD: Makefile,v 1.53 2008/06/12 02:14:20 joerg Exp $

DISTNAME=		PyGreSQL-3.8.1
PKGNAME=		${PYPKGPREFIX}-postgresql-3.8.1
PKGREVISION=		2
CATEGORIES=		databases python
MASTER_SITES=		ftp://ftp.druid.net/pub/distrib/
EXTRACT_SUFX=		.tgz

MAINTAINER=		darcy@NetBSD.org
HOMEPAGE=		http://www.PyGreSQL.org/
COMMENT=		Python interface to PostgreSQL

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_ENV+=		MANDIR=${LOCALBASE}/man
MAKE_ENV+=		BINDIR=${LOCALBASE}/bin
USE_TOOLS+=		gmake

MAKE_FILE=		GNUmakefile
MAKE_ENV+=		INSTALLED_LIBPQ=1

PY_PATCHPLIST=		yes
PLIST_SUBST+=		PYPKGPREFIX=${PYPKGPREFIX:Q}

PYDISTUTILSPKG=		yes
PYBINMODULE=		yes
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

.include "../../lang/python/extension.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
