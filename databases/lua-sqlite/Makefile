# $NetBSD: Makefile,v 1.18 2014/05/03 13:01:24 alnsn Exp $
#

DISTNAME=	lsqlite_src
PKGNAME=	${LUA_PKGPREFIX}-sqlite-20030228
PKGREVISION=	8
CATEGORIES=	databases
MASTER_SITES=	http://lua-users.org/files/wiki_insecure/binary_modules/luasqlite/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lua-users.org/wiki/LuaSqlite
COMMENT=	SQLite binding for LUA

WRKSRC=		${WRKDIR}

CFLAGS+=	-fPIC
LIBS+=		-llua -lsqlite

LUA_VERSIONS_INCOMPATIBLE=	52

AUTO_MKDIRS=		yes
INSTALLATION_DIRS+=	${LUA_CDIR} ${LUA_DOCDIR} ${LUA_EXAMPLESDIR}

do-build:
	cd ${WRKSRC}; ${CC} -shared ${CFLAGS} ${LDFLAGS} lsqlite.c	\
		-o libluasqlite.so ${LIBS}

do-install:
	${INSTALL_DATA} ${WRKSRC}/libluasqlite.so \
	    ${DESTDIR}${PREFIX}/${LUA_CDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt \
		${DESTDIR}${PREFIX}/${LUA_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/test.lua \
		${DESTDIR}${PREFIX}/${LUA_EXAMPLESDIR}

.include "../../databases/sqlite/buildlink3.mk"
.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
