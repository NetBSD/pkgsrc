# $NetBSD: Makefile,v 1.1.1.1 2009/01/24 03:04:54 obache Exp $
#

DISTNAME=	tokyocabinet-lua-1.4
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/-lua-/-/}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tokyocabinet/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://tokyocabinet.sourceforge.net/luadoc/
COMMENT=	Lua binding of Tokyo Cabinet

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config pax

TEST_TARGET=	check
TEST_ENV+=	LUA_CDIR=${WRKSRC}

FIND_PREFIX:=	LUADIR=lua
.include "../../mk/find-prefix.mk"

REPLACE_INTERPRETER+=	lua
REPLACE.lua.old=	.*lua
REPLACE.lua.new=	${LUADIR}/bin/lua
REPLACE_FILES.lua=	*.lua

INSTALLATION_DIRS+=	share/tokyocabinet/doc/lua

post-install:
	cd ${WRKSRC}/doc && pax -rwpe . \
		${DESTDIR}${PREFIX}/share/tokyocabinet/doc/lua

BUILDLINK_API_DEPENDS.tokyocabinet+=	tokyocabinet>=1.3.11
.include "../../databases/tokyocabinet/buildlink3.mk"
.include "../../lang/lua/module.mk"
PTHREAD_AUTO_VARS=	yes
.include "../../mk/pthread.buildlink3.mk"
.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} != "none"
SUBST_CLASSES+=		pthread
SUBST_STAGE.pthread=	pre-configure
SUBST_FILES.pthread=	configure
SUBST_SED.pthread=	-e 's|-lpthread|${PTHREAD_LIBS}|'
.endif
.include "../../mk/bsd.pkg.mk"
