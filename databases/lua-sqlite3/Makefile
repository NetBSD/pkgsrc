# $NetBSD: Makefile,v 1.2 2013/10/19 09:07:01 adam Exp $

DISTNAME=	lua-sqlite3-0.4.1
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
