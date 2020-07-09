# $NetBSD: Makefile,v 1.1 2020/07/09 16:12:57 nia Exp $

.include "Makefile.common"

PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/^lua//1}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Multi-backend SQL database library for Lua

NO_BUILD=	yes
USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	${LUA_LDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/DBI.lua ${DESTDIR}${PREFIX}/${LUA_LDIR}/DBI.lua

.include "../../mk/bsd.pkg.mk"
