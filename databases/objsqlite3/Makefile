# $NetBSD: Makefile,v 1.1 2024/08/11 12:08:12 js Exp $

DISTNAME=	objsqlite3-1.0
CATEGORIES=	database
MASTER_SITES=	https://fl.nil.im/objsqlite3/tarball/${PKGVERSION_NOREV}-release/

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://fl.nil.im/objsqlite3
COMMENT=	SQLite3 bindings for ObjFW
LICENSE=	isc

USE_LANGUAGES=		objc
USE_TOOLS+=		pkg-config
PKGSRC_COMPILER=	clang	# Needs to be the same as devel/objfw

.include "../../devel/objfw/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
