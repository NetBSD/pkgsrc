# $NetBSD: Makefile,v 1.2 2004/10/03 00:13:18 tv Exp $
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
USE_BUILDLINK3=	yes

do-build:
	${CC} ${WRKSRC}/lsqlite.c ${CFLAGS} ${LDFLAGS} \
	-shared -llua -lsqlite -llualib -o ${WRKSRC}/libluasqlite.so

do-install:
	${INSTALL_DATA} ${WRKSRC}/libluasqlite.so ${PREFIX}/lib

.include "../../databases/sqlite/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
