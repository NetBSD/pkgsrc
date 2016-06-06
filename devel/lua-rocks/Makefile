# $NetBSD: Makefile,v 1.1.1.1 2016/06/06 21:31:52 alnsn Exp $

DISTNAME=	luarocks-2.3.0
PKGNAME=	${DISTNAME:S/luarocks/${LUA_PKGPREFIX}-rocks/}
CATEGORIES=	devel
MASTER_SITES=	http://luarocks.org/releases/

MAINTAINER=	alnsn@NetBSD.org
HOMEPAGE=	http://luarocks.org/
COMMENT=	Deployment and management system for Lua modules
LICENSE=	mit

USE_TOOLS+=	curl:run    # downloader (curl or wget)
USE_TOOLS+=	openssl:run # md5-checker (openssl or md5sum)

.include "../../mk/bsd.prefs.mk"

HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none

REPLACE_LUA+=		src/bin/luarocks src/bin/luarocks-admin

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--rocks-tree=${PREFIX}/luarocks
CONFIGURE_ARGS+=	--with-lua=${PREFIX}
CONFIGURE_ARGS+=	--lua-suffix=${_LUA_DOT_VERSION}
CONFIGURE_ARGS+=	--lua-version=${_LUA_DOT_VERSION}
CONFIGURE_ARGS+=	--with-lua-include=${PREFIX}/${LUA_INCDIR}
CONFIGURE_ARGS+=	--versioned-rocks-dir
CONFIGURE_ARGS+=	--with-downloader=curl
CONFIGURE_ARGS+=	--with-md5-checker=openssl

BUILD_TARGET=		build
MAKE_ENV+=		LUA_EXAMPLESDIR=${LUA_EXAMPLESDIR}

PKG_SYSCONFSUBDIR=	luarocks
LUAROCKS_CONF=		config-${_LUA_DOT_VERSION}.lua
CONF_FILES=		${LUA_EXAMPLESDIR}/${LUAROCKS_CONF} \
			${PKG_SYSCONFDIR}/${LUAROCKS_CONF}

# XXX Add subst rules to ../../lang/lua/xxx.mk
PLIST_SUBST+=		LUADOTVER=${_LUA_DOT_VERSION}
FILES_SUBST+=		LUADOTVER=${_LUA_DOT_VERSION}

.include "../../lang/lua/application.mk"
.include "../../lang/lua/module.mk"
.include "../../mk/alternatives.mk"
.include "../../mk/bsd.pkg.mk"
