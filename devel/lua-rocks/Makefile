# $NetBSD: Makefile,v 1.19 2023/01/04 22:27:08 nikita Exp $

DISTNAME=	luarocks-3.9.2
PKGNAME=	${DISTNAME:S/luarocks/${LUA_PKGPREFIX}-rocks/}
CATEGORIES=	devel lua
MASTER_SITES=	https://luarocks.org/releases/

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://luarocks.org/
COMMENT=	Deployment and management system for Lua modules
LICENSE=	mit

USE_TOOLS+=	gmake
USE_TOOLS+=	curl:run	# downloader (curl or wget)
USE_TOOLS+=	openssl:run	# md5-checker (openssl or md5sum)
USE_TOOLS+=	unzip:run	# extraction

MAKE_FILE=	GNUmakefile

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
TOOLS_PLATFORM.unzip=	# it seems to not like netbsd unzip(1)
.endif

HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--rocks-tree=${PREFIX}/luarocks
CONFIGURE_ARGS+=	--with-lua=${PREFIX}
CONFIGURE_ARGS+=	--with-lua-include=${PREFIX}/${LUA_INCDIR}
CONFIGURE_ARGS+=	--lua-version=${_LUA_DOT_VERSION}

BUILD_TARGET=		build
MAKE_ENV+=		LUA_EXAMPLESDIR=${LUA_EXAMPLESDIR}

PKG_SYSCONFSUBDIR=	luarocks
LUAROCKS_CONF=		config-${_LUA_DOT_VERSION}.lua
CONF_FILES=		${LUA_EXAMPLESDIR}/${LUAROCKS_CONF} \
			${PKG_SYSCONFDIR}/${LUAROCKS_CONF}

# XXX Add subst rules to ../../lang/lua/xxx.mk
PLIST_SUBST+=		LUADOTVER=${_LUA_DOT_VERSION}
FILES_SUBST+=		LUADOTVER=${_LUA_DOT_VERSION}

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	src/luarocks/core/cfg.lua
SUBST_VARS.prefix=	PREFIX

.include "../../lang/lua/application.mk"
.include "../../lang/lua/module.mk"
.include "../../mk/alternatives.mk"
.include "../../mk/bsd.pkg.mk"
