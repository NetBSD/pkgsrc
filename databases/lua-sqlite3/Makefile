# $NetBSD: Makefile,v 1.3 2013/10/30 06:03:38 dholland Exp $

DISTNAME=	lua-sqlite3-0.4.1
PKGNAME=	${LUA_PKGPREFIX}-sqlite3-0.4.1
PKGREVISION=	1
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
