# $NetBSD: Makefile,v 1.2 2011/02/02 09:03:09 adam Exp $

DISTNAME=	sqlite-doc-3070500
PKGNAME=	sqlite3-docs-3.7.5
CATEGORIES=	databases
MASTER_SITES=	http://www.hwaci.com/sw/sqlite/ \
		http://www.sqlite.org/
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

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
USE_TOOLS+=	find xargs pax

DOCDIR=			share/doc/sqlite3
INSTALLATION_DIRS+=	${DOCDIR}

post-extract:
	find ${WRKSRC} -type f -print | xargs chmod 644
	find ${WRKSRC} -type d -print | xargs chmod 755

do-build:
	${TRUE}

do-install:
	cd ${WRKSRC} && ${PAX} -rw . ${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../mk/bsd.pkg.mk"
