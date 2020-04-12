# $NetBSD: Makefile,v 1.21 2020/04/12 08:28:25 adam Exp $

DISTNAME=	lua-sqlite3-0.4.1
PKGNAME=	${LUA_PKGPREFIX}-sqlite3-0.4.1
PKGREVISION=	17
CATEGORIES=	databases
MASTER_SITES=	https://www.mroth.net/lua-sqlite3/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.mroth.net/lua-sqlite3/
COMMENT=	SQLite3 binding for LUA
LICENSE=	mit

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--libdir=${PREFIX}/${LUA_CDIR}
CONFIGURE_ARGS+=	--with-lua=${LUA_INTERPRETER:Q}

CFLAGS+=		-fPIC

INSTALLATION_DIRS+=	${LUA_LDIR} ${LUA_CDIR}

post-install:
	mv ${DESTDIR}${PREFIX}/${LUA_CDIR}/*.lua \
	   ${DESTDIR}${PREFIX}/${LUA_LDIR}

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
