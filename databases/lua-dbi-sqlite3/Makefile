# $NetBSD: Makefile,v 1.7 2023/04/19 08:09:24 adam Exp $

PKGREVISION= 6
.include "../../databases/lua-dbi/Makefile.common"

PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/^lua//1:S/dbi/dbi-sqlite3/1}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Multi-backend SQL database library for Lua (sqlite3 backend)

DEPENDS+=	${LUA_PKGPREFIX}-dbi-[0-9]*:../../databases/lua-dbi

BUILD_TARGET=	sqlite3

INSTALLATION_DIRS+=	${LUA_CDIR}/dbd

do-install:
	${INSTALL_LIB} ${WRKSRC}/dbd/sqlite3.so \
		${DESTDIR}${PREFIX}/${LUA_CDIR}/dbd

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
