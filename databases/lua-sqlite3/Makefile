# $NetBSD: Makefile,v 1.8 2015/04/06 08:17:23 adam Exp $

DISTNAME=	lua-sqlite3-0.4.1
PKGNAME=	${LUA_PKGPREFIX}-sqlite3-0.4.1
PKGREVISION=	6
CATEGORIES=	databases
MASTER_SITES=	http://www.mroth.net/lua-sqlite3/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mroth.net/lua-sqlite3/
COMMENT=	SQLite3 binding for LUA
LICENSE=	mit

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--libdir=${PREFIX}/${LUA_CDIR}
CONFIGURE_ARGS+=	--with-lua=${LUA_INTERPRETER:Q}

CFLAGS+=		-fPIC

INSTALLATION_DIRS+= 	${LUA_LDIR} ${LUA_CDIR}

post-install:
	mv ${DESTDIR}${PREFIX}/${LUA_CDIR}/*.lua \
	   ${DESTDIR}${PREFIX}/${LUA_LDIR}

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
