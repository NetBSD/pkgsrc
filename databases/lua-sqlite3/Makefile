# $NetBSD: Makefile,v 1.1 2013/07/04 18:06:24 adam Exp $

DISTNAME=	lua-sqlite3-0.4.1
CATEGORIES=	databases
MASTER_SITES=	http://www.mroth.net/lua-sqlite3/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mroth.net/lua-sqlite3/
COMMENT=	SQLite3 binding for LUA
LICENSE=	mit

GNU_CONFIGURE=		yes

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
