# $NetBSD: Makefile,v 1.1 2020/07/09 16:12:57 nia Exp $

.include "../../databases/lua-dbi/Makefile.common"

PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/^lua//1:S/dbi/dbi-postgresql/1}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Multi-backend SQL database library for Lua (postgresql backend)

DEPENDS+=	${LUA_PKGPREFIX}-dbi-[0-9]*:../../databases/lua-dbi

BUILD_TARGET=	psql

INSTALLATION_DIRS+=	${LUA_CDIR}/dbd

do-install:
	${INSTALL_LIB} ${WRKSRC}/dbd/postgresql.so \
		${DESTDIR}${PREFIX}/${LUA_CDIR}/dbd

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
