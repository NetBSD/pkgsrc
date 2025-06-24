# $NetBSD: Makefile,v 1.8 2025/06/24 21:29:58 js Exp $

PKGNAME=	objsqlite3-1.0.1
DISTNAME=	${PKGVERSION_NOREV}-release
CATEGORIES=	databases
MASTER_SITES=	https://git.nil.im/ObjFW/ObjSQLite3/archive/
DIST_SUBDIR=	objsqlite3

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://git.nil.im/ObjFW/ObjSQLite3
COMMENT=	SQLite3 bindings for ObjFW
LICENSE=	isc

WRKSRC=			${WRKDIR}/objsqlite3
USE_LANGUAGES=		objc
USE_TOOLS+=		pkg-config
PKGSRC_COMPILER=	clang	# Needs to be the same as devel/objfw

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Darwin"
TOOL_DEPENDS+=		clang>=3.2:../../lang/clang
.endif

.include "../../devel/objfw/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
