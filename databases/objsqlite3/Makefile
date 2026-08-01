# $NetBSD: Makefile,v 1.10 2026/08/01 22:56:42 js Exp $

PKGNAME=	objsqlite3-1.1
DISTNAME=	${PKGVERSION_NOREV}-release
CATEGORIES=	databases
MASTER_SITES=	https://git.nil.im/ObjFW/ObjSQLite3/archive/
DIST_SUBDIR=	objsqlite3

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://git.nil.im/ObjFW/ObjSQLite3
COMMENT=	SQLite3 bindings for ObjFW
LICENSE=	isc

WRKSRC=			${WRKDIR}/objsqlite3
GNU_CONFIGURE=		yes
USE_LANGUAGES=		objc
PKGSRC_COMPILER=	clang	# Needs to be the same as devel/objfw
USE_TOOLS+=		autoconf automake

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Darwin"
TOOL_DEPENDS+=		clang>=3.2:../../lang/clang
.endif

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../devel/objfw/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
