# $NetBSD: Makefile,v 1.5 2024/12/18 10:31:34 wiz Exp $

DISTNAME=	objsqlite3-1.0
PKGREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	https://fl.nil.im/objsqlite3/tarball/${PKGVERSION_NOREV}-release/

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://fl.nil.im/objsqlite3
COMMENT=	SQLite3 bindings for ObjFW
LICENSE=	isc

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
