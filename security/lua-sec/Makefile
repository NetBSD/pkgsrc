# $NetBSD: Makefile,v 1.1.1.1 2010/09/21 10:45:56 fhajny Exp $
#

DISTNAME=		luasec-0.4
PKGNAME=		${LUA_PKGPREFIX}-${DISTNAME:S/lua//}
CATEGORIES=		security
MASTER_SITES=		http://luaforge.net/frs/download.php/4255/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.inf.puc-rio.br/~brunoos/luasec/
COMMENT=		Lua binding for OpenSSL library
LICENSE=		mit

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

DEPENDS+=		lua-socket>=2.0:../../net/lua-socket

USE_TOOLS+=		gmake

INSTALLATION_DIRS+=	${LUA_CDIR} ${LUA_LDIR}

.if ${OPSYS} == "SunOS"
BUILD_TARGET=		solaris
.else
BUILD_TARGET=		bsd
.endif

INSTALL_ENV+=		LUA_CDIR=${LUA_CDIR}
INSTALL_ENV+=		LUA_LDIR=${LUA_LDIR}

.include "../../lang/lua/module.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
