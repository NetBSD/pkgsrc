# $NetBSD: Makefile,v 1.45 2018/11/07 11:51:25 adam Exp $

# docs for latest version are not available
#DISTNAME=	sqlite-doc-${SQLITE3_DISTVERSION}
#PKGNAME=	sqlite3-docs-${SQLITE3_VERSION}

DISTNAME=	sqlite-doc-3250200
PKGNAME=	sqlite3-docs-3.25.2
CATEGORIES=	databases
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	SQL Database Engine in a C Library (docs package)
# "Portions of the documentation and some code used as part of the
# build process might fall under other licenses.  We do not worry
# about the licensing of the documentation and build code so much
# because none of these things are part of the core deliverable SQLite
# library."

.include "../../databases/sqlite3/Makefile.common"

USE_LANGUAGES=	# none
USE_TOOLS+=	find xargs pax

NO_CONFIGURE=		yes
NO_BUILD=		yes
DOCDIR=			share/doc/sqlite3
INSTALLATION_DIRS+=	${DOCDIR}

do-install:
	cd ${WRKSRC} && ${PAX} -rw . ${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../mk/bsd.pkg.mk"
