# $NetBSD: Makefile,v 1.1 2025/05/20 16:46:24 schmonz Exp $

.include "../../databases/sqlite3/Makefile.common"

DISTNAME=		sqlite-src-${SQLITE3_DISTVERSION}
PKGNAME=		sqlite3-diff-${SQLITE3_VERSION}
CATEGORIES=		databases
EXTRACT_SUFX=		.zip

MAINTAINER=		schmonz@NetBSD.org
COMMENT=		Display content differences between SQLite databases

HAS_CONFIGURE=		yes

BUILD_TARGET=		sqldiff

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sqldiff ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
