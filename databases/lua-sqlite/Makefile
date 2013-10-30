# $NetBSD: Makefile,v 1.16 2013/10/30 06:19:42 dholland Exp $
#

DISTNAME=	lsqlite_src
PKGNAME=	${LUA_PKGPREFIX}-sqlite-20030228
PKGREVISION=	7
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
.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
