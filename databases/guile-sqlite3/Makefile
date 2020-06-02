# $NetBSD: Makefile,v 1.5 2020/06/02 08:23:25 adam Exp $

DISTNAME=	v0.1.0
DIST_SUBDIR=	${PKGNAME_NOREV}
PKGNAME=	guile-sqlite3-${DISTNAME:S/v//}
PKGREVISION=	2
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

.include "../../lang/guile22/module.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
