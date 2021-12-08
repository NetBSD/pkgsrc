# $NetBSD: Makefile,v 1.4 2021/12/08 16:03:39 adam Exp $

PKGREVISION= 3
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
