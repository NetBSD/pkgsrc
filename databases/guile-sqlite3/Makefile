# $NetBSD: Makefile,v 1.22 2026/03/30 16:39:08 gdt Exp $

DISTNAME=	v0.1.3
DIST_SUBDIR=	${PKGNAME_NOREV}
PKGNAME=	guile-sqlite3-${DISTNAME:S/v//}
PKGREVISION=	11
CATEGORIES=	databases
# \todo Update to codeberg
MASTER_SITES=	https://notabug.org/guile-sqlite3/guile-sqlite3/archive/

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://codeberg.org/guile-sqlite3/guile-sqlite3.git
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
