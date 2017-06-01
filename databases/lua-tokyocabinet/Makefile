# $NetBSD: Makefile,v 1.26 2017/06/01 13:30:24 jlam Exp $
#

DISTNAME=	tokyocabinet-lua-1.10
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/-lua-/-/}
PKGREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	${HOMEPAGE:S/luadoc/luapkg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fallabs.com/tokyocabinet/luadoc/
COMMENT=	Lua binding of Tokyo Cabinet
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config pax

TEST_TARGET=	check
TEST_ENV+=	LUA_CDIR=${WRKSRC}

REPLACE_LUA=		*.lua

INSTALLATION_DIRS+=	${LUA_DOCDIR} ${LUA_EXAMPLESDIR}

MAKE_ENV+=	INCLUDEDIR=${BUILDLINK_PREFIX.tokyocabinet}/include

.include "../../mk/bsd.prefs.mk"

.if ${SHLIB_TYPE} == "dylib"
SOEXT= 		dylib
.else
SOEXT= 		so
.endif
PLIST_SUBST+= 	SOEXT=${SOEXT}

post-extract:
	${CHMOD} -R go-w ${WRKSRC}

post-install:
	cd ${WRKSRC}/doc && pax -rwpp . \
		${DESTDIR}${PREFIX}/${LUA_DOCDIR}
	mv ${DESTDIR}${PREFIX}/bin/*.lua \
		${DESTDIR}${PREFIX}/${LUA_EXAMPLESDIR}

BUILDLINK_API_DEPENDS.tokyocabinet+=	tokyocabinet>=1.4.29
.include "../../databases/tokyocabinet/buildlink3.mk"
.include "../../lang/lua/application.mk"
.include "../../lang/lua/module.mk"
.include "../../lang/lua/tool.mk"
PTHREAD_AUTO_VARS=	yes
.include "../../mk/pthread.buildlink3.mk"
.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} != "none"
SUBST_CLASSES+=		pthread
SUBST_STAGE.pthread=	pre-configure
SUBST_FILES.pthread=	configure
SUBST_SED.pthread=	-e 's|-lpthread|${PTHREAD_LIBS}|'
.endif
.include "../../mk/bsd.pkg.mk"
