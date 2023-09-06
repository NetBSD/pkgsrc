# $NetBSD: Makefile,v 1.6 2023/09/06 11:48:15 wiz Exp $

DISTNAME=	lua-${LUA_VERSION}
PKGNAME=	lua54-${LUA_VERSION}
PKGREVISION=	1
CATEGORIES=	lang lua
MASTER_SITES=	https://www.lua.org/ftp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.lua.org/
COMMENT=	Lightweight, embeddable scripting language (v5.4)
LICENSE=	mit

.include "../../lang/lua54/version.mk"

CONFLICTS+=	lua-[0-9]*

USE_TOOLS+=	gmake
USE_LIBTOOL=	yes

.include "../../mk/bsd.prefs.mk"

MAKE_FLAGS+=	MYCFLAGS="-DLUA_USE_READLINE"
MAKE_FLAGS+=	INSTALL_TOP=${PREFIX}
MAKE_FLAGS+=	INSTALL_INC=${PREFIX}/include/lua-5.4
MAKE_FLAGS+=	INSTALL_MAN=${PREFIX}/${PKGMANDIR}/man1

# Address pkg/47587 lua not linked to pthread causes issues with modules
PTHREAD_OPTS+=		native

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "native"
CFLAGS+=	-pthread
LDFLAGS+=	-pthread
.endif

.if ${OPSYS:M*BSD*} || ${OPSYS} == "DragonFly"
BUILD_TARGET=	bsd
.elif ${OPSYS} == "Linux"
BUILD_TARGET=	linux
.elif ${OPSYS} == "Darwin"
BUILD_TARGET=	macosx
.elif ${OPSYS} == "SunOS"
BUILD_TARGET=	solaris
.elif ${OPSYS} == "AIX"
BUILD_TARGET=	aix
.else
BUILD_TARGET=	posix
.endif

DOCDIR=		${PREFIX}/share/doc/lua-5.4

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix+=	src/luaconf.h
SUBST_SED.prefix+=	-e "s,/usr/local,${PREFIX},g"

PKGCONFIG_OVERRIDE=	lua.pc
INSTALLATION_DIRS+=	bin lib include/lua-5.4
INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	lib/pkgconfig share/doc/lua-5.4

pre-configure:
	sed	-e 's,@PREFIX@,${PREFIX},g' \
		-e 's,@VER@,${PKGVERSION_NOREV:R},g' \
		-e 's,@REV@,${PKGVERSION_NOREV},g' \
		${FILESDIR}/lua.pc.in > ${WRKSRC}/lua.pc
	cp ${WRKSRC}/doc/lua.1  ${WRKSRC}/doc/lua5.4.1
	cp ${WRKSRC}/doc/luac.1 ${WRKSRC}/doc/luac5.4.1

do-install:
	${LIBTOOL} --quiet --tag=CC --mode=install \
	    ${INSTALL_PROGRAM} ${WRKSRC}/src/lua ${DESTDIR}${PREFIX}/bin/lua5.4
	${LIBTOOL} --quiet --tag=CC --mode=install \
	    ${INSTALL_PROGRAM} ${WRKSRC}/src/luac ${DESTDIR}${PREFIX}/bin/luac5.4
	${LIBTOOL} --quiet --tag=CC --mode=install \
	    ${INSTALL_LIB} ${WRKSRC}/src/liblua5.4.la ${DESTDIR}${PREFIX}/lib
	cd ${WRKSRC}/src && ${INSTALL_DATA} lua.h luaconf.h lualib.h lauxlib.h lua.hpp \
	    ${DESTDIR}${PREFIX}/include/lua-5.4
	${INSTALL_MAN} ${WRKSRC}/doc/lua.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/lua5.4.1
	${INSTALL_MAN} ${WRKSRC}/doc/luac.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/luac5.4.1
	${INSTALL_DATA} ${WRKSRC}/doc/*.[a-z][a-z][a-z] \
	    ${WRKSRC}/doc/*.html ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/lua.pc \
	    ${DESTDIR}${PREFIX}/lib/pkgconfig/lua-5.4.pc

.include "../../mk/readline.buildlink3.mk"
.if ${READLINE_TYPE} == "editline"
MAKE_FLAGS+=	MYLIBS="-L${BUILDLINK_PREFIX.editlinereadline} -ledit"
.else
MAKE_FLAGS+=	MYLIBS="-L${BUILDLINK_PREFIX.editlinereadline} -lreadline"
.endif
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
