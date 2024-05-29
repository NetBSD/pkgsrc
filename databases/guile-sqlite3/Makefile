# $NetBSD: Makefile,v 1.16 2024/05/29 16:31:40 adam Exp $

DISTNAME=	v0.1.3
DIST_SUBDIR=	${PKGNAME_NOREV}
PKGNAME=	guile-sqlite3-${DISTNAME:S/v//}
PKGREVISION=	6
CATEGORIES=	databases
MASTER_SITES=	https://notabug.org/guile-sqlite3/guile-sqlite3/archive/

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://notabug.org/guile-sqlite3/guile-sqlite3/
COMMENT=	Guile bindings for the SQLite3 database engine
LICENSE=	gnu-gpl-v3

WRKSRC=			${WRKDIR}/guile-sqlite3
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		YES
GUILE_NEED_BOOTSTRAP=	YES

# not all sqlite3.pc files provide the pkg-config variable, set path manually
# see also patch-configure.ac
CONFIGURE_ARGS+=	SQLITE_LIBDIR=${BUILDLINK_PREFIX.sqlite3}/lib

TEST_TARGET=		check

.include "../../lang/guile30/module.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
