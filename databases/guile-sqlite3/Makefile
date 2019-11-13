# $NetBSD: Makefile,v 1.1 2019/11/13 12:52:25 ng0 Exp $

DISTNAME=	v0.1.0
DIST_SUBDIR=	${PKGNAME_NOREV}
PKGNAME=	guile-sqlite3-${DISTNAME:S/v//}
CATEGORIES=	databases
MASTER_SITES=	https://notabug.org/guile-sqlite3/guile-sqlite3/archive/

MAINTAINER=	ng0@NetBSD.org
HOMEPAGE=	https://notabug.org/guile-sqlite3/guile-sqlite3/
COMMENT=	Guile bindings for the SQLite3 database engine
LICENSE=	gnu-gpl-v3

WRKSRC=			${WRKDIR}/guile-sqlite3
USE_LANGUAGES=		c
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		YES
GUILE_NEED_BOOTSTRAP=	YES

# not all sqlite3.pc files provide the pkg-config variable, set path manually
# see also patch-configure.ac
CONFIGURE_ARGS+=	SQLITE_LIBDIR=${BUILDLINK_PREFIX.sqlite3}/lib

TEST_TARGET=		check

.include "../../lang/guile22/module.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
