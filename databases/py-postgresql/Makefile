# $NetBSD: Makefile,v 1.43 2005/12/05 20:50:00 rillig Exp $

DISTNAME=		PyGreSQL-3.7
PKGNAME=		${PYPKGPREFIX}-postgresql-3.7
CATEGORIES=		databases python
MASTER_SITES=	ftp://ftp.druid.net/pub/distrib/
EXTRACT_SUFX=	.tgz

MAINTAINER=		darcy@NetBSD.org
HOMEPAGE=		http://www.PyGreSQL.org/
COMMENT=		Python interface to PostgreSQL

MAKE_ENV+=		MANDIR=${LOCALBASE}/man
MAKE_ENV+=		BINDIR=${LOCALBASE}/bin
USE_TOOLS+=	gmake

MAKEFILE=		GNUmakefile
MAKE_ENV+=		INSTALLED_LIBPQ=1

PY_PATCHPLIST=	yes
PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX:Q}

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes
DOCDIR=			${PREFIX}/share/doc/${PYPKGPREFIX}-postgresql

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}/tutorial
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	for inst_file in ${WRKSRC}/tutorial/*.py; do   \
		${INSTALL_DATA} $${inst_file} ${DOCDIR}/tutorial;        \
	done

.include "../../lang/python/extension.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
