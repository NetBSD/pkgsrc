# $NetBSD: Makefile,v 1.27 2014/03/10 17:03:29 adam Exp $

DISTNAME=	sqlite-doc-3080400
PKGNAME=	sqlite3-docs-3.8.4
CATEGORIES=	databases
MASTER_SITES=	http://www.hwaci.com/sw/sqlite/2014/ \
		http://www.sqlite.org/2014/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sqlite.org/
COMMENT=	SQL Database Engine in a C Library (docs package)
# "Portions of the documentation and some code used as part of the
# build process might fall under other licenses.  We do not worry
# about the licensing of the documentation and build code so much
# because none of these things are part of the core deliverable SQLite
# library."
LICENSE=	public-domain

USE_LANGUAGES=	# none
USE_TOOLS+=	find xargs pax

NO_CONFIGURE=		yes
NO_BUILD=		yes
DOCDIR=			share/doc/sqlite3
INSTALLATION_DIRS+=	${DOCDIR}

do-install:
	cd ${WRKSRC} && ${PAX} -rw . ${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../mk/bsd.pkg.mk"
