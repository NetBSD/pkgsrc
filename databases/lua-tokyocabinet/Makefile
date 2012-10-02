# $NetBSD: Makefile,v 1.16 2012/10/02 21:25:21 asau Exp $
#

DISTNAME=	tokyocabinet-lua-1.9
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/-lua-/-/}
CATEGORIES=	databases
MASTER_SITES=	${HOMEPAGE:S/luadoc/luapkg/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://fallabs.com/tokyocabinet/luadoc/
COMMENT=	Lua binding of Tokyo Cabinet
LICENSE=	gnu-lgpl-v2.1

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

MAKE_ENV+=	INCLUDEDIR=${BUILDLINK_PREFIX.tokyocabinet}/include

post-extract:
	${CHMOD} -R go-w ${WRKSRC}

post-install:
	cd ${WRKSRC}/doc && pax -rwpe . \
		${DESTDIR}${PREFIX}/share/tokyocabinet/doc/lua

BUILDLINK_API_DEPENDS.tokyocabinet+=	tokyocabinet>=1.4.29
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
