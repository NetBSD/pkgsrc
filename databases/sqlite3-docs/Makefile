# $NetBSD: Makefile,v 1.38 2015/01/20 20:11:07 adam Exp $

DISTNAME=	sqlite-doc-3080801
PKGNAME=	sqlite3-docs-3.8.8.1
CATEGORIES=	databases
MASTER_SITES=	http://www.hwaci.com/sw/sqlite/2015/ \
		http://www.sqlite.org/2015/
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
