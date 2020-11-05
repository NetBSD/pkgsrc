# $NetBSD: Makefile,v 1.5 2020/11/05 09:07:41 ryoon Exp $

DISTNAME=	lsqlite3_fsl09y
PKGNAME=	${LUA_PKGPREFIX}-lsqlite3-0.9.5
PKGREVISION=	1
CATEGORIES=	databases lua
MASTER_SITES=	http://lua.sqlite.org/index.cgi/zip/
EXTRACT_SUFX=	.zip

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	http://lua.sqlite.org/index.cgi/index
COMMENT=	Binding for Lua to the SQLite3 database library
LICENSE=	mit

INSTALLATION_DIRS+=	${LUA_CDIR} ${LUA_LDIR}
INSTALLATION_DIRS+=	${LUA_DOCDIR}/examples

pre-build:
	# Don't use the internal copy of sqlite3
	${RM} -f ${WRKSRC}/sqlite3.h
	# Copy our makefile into place.
	${CP} -f ${FILESDIR}/Makefile ${WRKSRC}/Makefile

pre-install:
	# For compatibility with the statically linked variant.
	${PRINTF} '%s\n' 'return require("lsqlite3")' > ${WRKSRC}/lsqlite3complete.lua

do-install:
	${INSTALL_LIB} ${WRKSRC}/lsqlite3.so \
		${DESTDIR}${PREFIX}/${LUA_CDIR}/lsqlite3.so
	${INSTALL_LIB} ${WRKSRC}/lsqlite3complete.lua \
		${DESTDIR}${PREFIX}/${LUA_LDIR}/lsqlite3complete.lua
	${INSTALL_DATA} ${WRKSRC}/examples/*.lua \
		${DESTDIR}${PREFIX}/${LUA_DOCDIR}/examples

do-test:
	cd ${WRKSRC}/test && LUA_CPATH=${WRKSRC}/?.so ${LUA_INTERPRETER} test.lua

.include "../../lang/lua/module.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
