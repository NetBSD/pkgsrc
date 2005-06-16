# $NetBSD: Makefile,v 1.5 2005/06/16 06:57:44 jlam Exp $
#

DISTNAME=	lsqlite_src
PKGNAME=	lua-sqlite-20030228
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://lua-users.org/files/wiki_insecure/binary_modules/luasqlite/
EXTRACT_SUFX=	.zip

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://lua-users.org/wiki/LuaSqlite
COMMENT=	SQLite binding for LUA

WRKSRC=		${WRKDIR}

CFLAGS+=	-fPIC
LIBS+=		-llua -lsqlite -llualib

INSTALLATION_DIRS=	lib

do-build:
	cd ${WRKSRC}; ${CC} -shared ${CFLAGS} ${LDFLAGS} lsqlite.c	\
		-o libluasqlite.so ${LIBS}

do-install:
	${INSTALL_DATA} ${WRKSRC}/libluasqlite.so ${PREFIX}/lib

.include "../../databases/sqlite/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
