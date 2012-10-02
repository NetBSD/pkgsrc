# $NetBSD: Makefile,v 1.14 2012/10/02 21:25:21 asau Exp $
#

DISTNAME=	lsqlite_src
PKGNAME=	lua-sqlite-20030228
PKGREVISION=	6
CATEGORIES=	databases
MASTER_SITES=	http://lua-users.org/files/wiki_insecure/binary_modules/luasqlite/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lua-users.org/wiki/LuaSqlite
COMMENT=	SQLite binding for LUA

WRKSRC=		${WRKDIR}

CFLAGS+=	-fPIC
LIBS+=		-llua -lsqlite

AUTO_MKDIRS=	yes

do-build:
	cd ${WRKSRC}; ${CC} -shared ${CFLAGS} ${LDFLAGS} lsqlite.c	\
		-o libluasqlite.so ${LIBS}

do-install:
	${INSTALL_DATA} ${WRKSRC}/libluasqlite.so ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/readme.txt \
		${DESTDIR}${PREFIX}/share/doc/lua-sqlite
	${INSTALL_DATA} ${WRKSRC}/test.lua \
		${DESTDIR}${PREFIX}/share/examples/lua-sqlite

.include "../../databases/sqlite/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
